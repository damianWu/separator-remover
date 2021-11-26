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
    void case_sensitive(bool b);
    bool is_whitespace(char ch) const;
    bool is_case_sensitive() const;

    PunctStream& operator>>(std::string& s);
    explicit operator bool() const;

 private:
    std::istream& source_;
    std::istringstream buffer_;
    std::string white_;
    bool sensitive_;
};

#endif  // PUNCT_STREAM_PUNCT_STREAM_HPP
