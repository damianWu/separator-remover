#include <iostream>
#include <vector>

#include "punct_stream/punct_stream.hpp"
#include "utils/exception.hpp"

// Example #1
//
// Init:    case senstitive -> true
// Input:   For any integer N, do sth.
// Output:  For any integer N do sth

// Example #2
//
// Init:    case senstitive -> false
// Input:   for any; integer N, do sth.
// Output:  for any integer n do sth

// Example #3
//
// Init:    case senstitive -> false
// Input:   There are only two kinds of languages: languages that people
//          complain about, and languages that people don't use.
// Output:  about
//          and
//          are
//          complain
//          don't
//          kind
//          languages
//          of
//          only
//          people
//          that
//          there
//          two
//          use

int main() {
    try {
        PunctStream ps{std::cin};
        ps.whitespace(";:.,");
        ps.case_sensitive(false);

        std::vector<std::string> words;
        for (std::string s; ps >> s;) {
            words.emplace_back(s);
        }

        std::sort(words.begin(), words.end());
        auto words_size{words.size()};
        for (size_t i = 0; i < words_size; ++i) {
            // Print without duplicates
            if (i == 0 || words.at(i) != words.at(i - 1)) {
                std::cout << words.at(i) << '\n';
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    return 0;
}
