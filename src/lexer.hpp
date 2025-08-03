#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <optional>
#include <vector>
#include <cctype>

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

inline std::string readFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary | std::ios::ate);
    if (!file.is_open()) throw std::runtime_error("File not found or can't be opened");

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string buffer(size, '\0');
    if (!file.read(buffer.data(), size)) throw std::runtime_error("File read failed");

    return buffer;
}

inline std::vector<Token> tokenize(const std::string& str) {
    std::vector<Token> tokens{};
    std::string buff{};

    for (int i = 0; i < str.size(); i++) {
        char c = str.at(i);

        if (std::isalpha(c)) {
            buff.push_back(c);
            i++;
            while (i < str.size() && std::isalnum(str.at(i))) {
                buff.push_back(str.at(i));
                i++;
            }
            i--;
            if (buff == "return") {
                tokens.push_back(Token{.type = TokenType::_return});
                buff.clear();
            } else {
                std::cerr << "you suck\n";
                exit(1);
            }
         } else if (std::isdigit(c)) {
            buff.push_back(c);
            i++;
            while (i < str.size() && std::isdigit(str.at(i))) {
                buff.push_back(str.at(i));
                i++;
            }
            i--;
            tokens.push_back({.type = TokenType::int_lit, .value = buff});
            buff.clear();
        } else if (c == '\n' || c == ';') {
            tokens.push_back({.type = TokenType::semi});
        } else if (std::isspace(c)) {
            continue;
        } else {
            std::cout << "you suck 2" << std::endl;
        }
    }

    std::cout << "sigma";

    return tokens;
}
