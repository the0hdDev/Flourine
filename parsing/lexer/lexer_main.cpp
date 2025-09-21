#include "lexer_main.h"

using namespace lex;

char Lexer::gettok() {
    static char LastChar = ' ';
    while (isspace(LastChar)) {
        LastChar = getchar();
    }
    if (isalpha(LastChar))
    {
        // identifier: [a-zA-Z][a-zA-Z0-9]*
        Lexer::IdentStr = LastChar;
        while (isalnum((LastChar = getchar())))
            Lexer::IdentStr += LastChar;

        if (Lexer::IdentStr == "func")
        {
            return Lexer::token_func;
        }

        if (Lexer::IdentStr == "extern")
        {
            return Lexer::token_extern;
        }

        if (Lexer::IdentStr == "return"){
            return Lexer::token_return;
        }
    }


    if (isdigit(LastChar) || LastChar == '.')
    {
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');
        NumVal = strtod(NumStr.c_str(), 0);
        return token_number;
    }

    if (LastChar == '/') {
        int NextChar = getchar();
        if (NextChar == '/') {
            do {
                LastChar = getchar();
            } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

            if (LastChar != EOF)
                return gettok();
        } else {
            LastChar = NextChar;
            return token_slash;
        }
    }


    return Lexer::token_identifier;
}