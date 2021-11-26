#include "punct_stream/punct_stream.hpp"

PunctStream::PunctStream(std::istream& is) : source_{is}, sensitive_{true} {}
void PunctStream::whitespace(const std::string& s) { white_ = s; }
void PunctStream::add_white(char ch) { white_ += ch; }
bool PunctStream::is_whitespace(char ch) const {
    for (const auto& e : white_) {
        if (ch == e) {
            return true;
        }
    }
    return false;
}

void PunctStream::case_sensitive(bool b) { sensitive_ = b; }
bool PunctStream::is_case_sensitive() const { return sensitive_; }

PunctStream& PunctStream::operator>>(std::string& s) {
    while (!(buffer_ >> s)) {  // Warunek zostaje spelniony tylko wtedy, gdy
                               // buffer jest pusty i chcemy doczytac dane
                               // ze strumienia std::cin (source).
        if (buffer_.bad() || !source_.good()) {
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
        buffer_.clear();

        std::string line;
        getline(source_, line);  // odczytaliśmy całą linijke, ale chcemy
                                 // zwrócić tylko pierwszy wyraz.
                                 // Może być wielolinijkowe.
        for (auto& ch : line) {
            if (is_whitespace(ch)) {
                ch = ' ';
            } else if (!sensitive_) {
                ch = char(tolower(ch));
            }
        }

        buffer_.str(line);  // Wstaw 'line' do istringstream
    }
    return *this;
}

PunctStream::operator bool() const {
    return source_.good();
}  // OR other condition that makes object true
