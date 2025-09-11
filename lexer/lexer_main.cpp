//
// Created by theo on 9/9/25.
//

#include "lexer_main.h"


inline std::string Lexer::readFile(const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary | std::ios::ate);
    if (!file.is_open()) throw std::runtime_error("File not found or can't be opened");

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::string buffer(size, '\0');
    if (!file.read(buffer.data(), size)) throw std::runtime_error("File read failed");

    return buffer;
}



inline std::vector<Lexer::Token> tokenize(const std::string& str) {
    std::vector<Lexer::Token> tokens{};
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
                tokens.push_back(Lexer::Token{.type = Lexer::TokenType::_return});
                buff.clear();
            } else {
                std::cerr << "Error\n";
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
            tokens.push_back({.type = Lexer::TokenType::int_lit, .value = buff});
            buff.clear();
        } else if (c == '\n' || c == ';') {
            tokens.push_back({.type = Lexer::TokenType::semi});
        } else if (std::isspace(c)) {
            continue;
        } else {
            std::cout << "you suck 2" << std::endl;
        }
    }

    std::cout << "sigma";

    return tokens;
}
