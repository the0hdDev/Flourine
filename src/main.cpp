#include <iostream>
#include <string>
#include "lexer.hpp"

std::strings tokenToAsm(const std::vector<Token>& tokens) {
    std::stringstream asmCode;
    asmCode << "global _start\nstart:\n";
    for (int i = 0; i < tokens.size(); i++) {
        const Token& token = tokens.at(i);
        if (token.type == TokenType::_return) {
            if (i+ 1 < tokens.size() && tokens.at(i + 1).type == TokenType::int_lit) {
                if (i + 2 < tokens.size() && tokens.at(i + 1).type == TokenType::semi) {
                    asmCode << "    mov rax, 60\n";
                    asmCode << "    mov rdi, " << tokens.at(i + 1).value.value() << "\n";
                }
            }
        }
    }

    return asmCode;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments!" << std::endl;
        return EXIT_FAILURE;
    }


    std::string fileContent = readFile(argv[1]);
    std::vector<Token> tokens = tokenize(fileContent);

    std::cout << std::to_string(tokenToAsm(tokens)) << std::endl;


    return EXIT_SUCCESS;
}
