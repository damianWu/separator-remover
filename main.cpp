#include <iostream>
#include <vector>

#include "punct_stream/punct_stream.hpp"
#include "utils/exception.hpp"

int main() {
    try {
        PunctStream ps{std::cin};
        ps.whitespace(";:.,");
        ps.case_sensitive(false);

        for (std::string s; ps >> s;) {
            std::cout << s << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception catch in main function with message: "
                  << e.what() << '\n';
    } catch (...) {
        std::cerr << "Unknown type of exception catch in main function" << '\n';
    }
    return 0;
}
