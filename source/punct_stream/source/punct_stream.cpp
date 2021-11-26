#include "punct_stream/punct_stream.hpp"

PunctStream::PunctStream(std::istream& is) : source{is}, sensitive{true} {}
void PunctStream::whitespace(const std::string& s) { white = s; }
void PunctStream::add_white(char ch) { white += ch; }
bool PunctStream::is_whitespace(char ch) {
    for (const auto& e : white) {
        if (ch == e) {
            return true;
        }
    }
    return false;
}

void PunctStream::case_sensitive(bool b) { sensitive = b; }
bool PunctStream::is_case_sensitive() { return sensitive; }

PunctStream& PunctStream::operator>>(std::string& s) {
    while (!(buffer >> s)) {  // Warunek zostaje spelniony tylko wtedy, gdy
                              // buffer jest pusty i chcemy doczytac dane
                              // ze strumienia std::cin (source).
        if (buffer.bad() || !source.good()) {
            // Cos moze pojsc zle. Nie wiemy co - moze tasma z której czytalimy
            // dane zostala przerwana, albo urzadzenie zczytujące pomiary ulego
            // awarii, dysk padł. Dlatego nalezy taki przypadek zawsze rozwazac.
            // Dlaczego 'buffer.bad()', a ;!source.good()'?
            // poniewaz buffer moze znaleźć sie w stanie fail i to jest
            // planowana czesc implementacji. bad dla buffer oznacza powazną
            // awarie strumienia.
            // !source.good() ponieważ jezeli zrodlo z ktorego czytamy uleglo
            // awarii (np. std::cin dla tego przykladu) wedlug mnie nie wiadomo
            // co moglo pojsc nie tak.
            return *this;
        }
        // Napraw, jesli buffer byl pusty (stan fail()) i weszlismy do petli
        // (sczytac dane)
        buffer.clear();

        std::string line;
        getline(source, line);  // odczytaliśmy całą linijke, ale chcemy zwrócić
                                // tylko pierwszy wyraz.
                                // Może być wielolinijkowe.
        for (auto& ch : line) {
            if (is_whitespace(ch)) {
                ch = ' ';
            } else if (!sensitive) {
                ch = char(tolower(ch));
            }
        }

        buffer.str(line);  // Wstaw 'line' do istringstream
    }
    return *this;
}

PunctStream::operator bool() const {
    return source.good();
}  // OR other condition that makes object true
