// Copyright [2021] <DamWu>
#ifndef PUNCT_STREAM_PUNCT_STREAM_HPP
#define PUNCT_STREAM_PUNCT_STREAM_HPP

#include <fstream>
#include <sstream>

class PunctStream {
 public:
    explicit PunctStream(std::istream& is);
    void whitespace(const std::string& s);
    void add_white(char ch);
    bool is_whitespace(char ch);
    void case_sensitive(bool b);
    bool is_case_sensitive();

    PunctStream& operator>>(std::string& s);
    explicit operator bool() const;

 private:
    std::istream& source;
    std::istringstream buffer;
    std::string white;
    bool sensitive;
};

#endif  // PUNCT_STREAM_PUNCT_STREAM_HPP
