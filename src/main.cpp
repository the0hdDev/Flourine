#include <iostream>
#include <string>
#include "lexer.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments!" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        std::string fileContent = readFile(argv[1]);
        auto tokens = tokenize(fileContent);

        for (const auto& token : tokens) {
            switch (token.type) {
                case TokenType::_return:
                    std::cout << "TOKEN: return\n";
                    break;
                case TokenType::int_lit:
                    std::cout << "TOKEN: int_lit, value = " << token.value.value_or("<none>") << "\n";
                    break;
                case TokenType::semi:
                    std::cout << "TOKEN: semi\n";
                    break;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
