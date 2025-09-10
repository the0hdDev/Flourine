#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <optional>
#include <vector>
#include <cctype>

class Lexer {
public:
Lexer() {};
~Lexer() {};
inline std::uint64_t getFileSize(const std::string& path) {
    return std::filesystem::file_size(path) + 1;
}

enum class TokenType {
    _return,
    int_lit,
    semi
};

struct Token {
    TokenType type;
    std::optional<std::string> value;
};

inline std::string readFile(const std::string& fileName);
inline std::vector<Token> tokenize(const std::string& str);

};
