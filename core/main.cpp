#include <iostream>
#include <string>
#include "../lexer/lexer_main.hpp"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments!" << std::endl;
        return EXIT_FAILURE;
    }

    Tokenizer* tokenizer = new Tokenizer();

    std::string fileContent = tokenizer->readFile(argv[1]);
    std::vector<Tokenizer::Token> tokens = tokenizer->tokenize(fileContent);

    std::cout << std::to_string(tokenizer->tokenToAsm(tokens)) << std::endl;


    return EXIT_SUCCESS;
}
