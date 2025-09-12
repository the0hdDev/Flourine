#include "lexer_main.h"

char lex::Lexer::gettok() {
    static char LastChar = ' ';
    while (isspace(LastChar)) {
        LastChar = getchar();
    }
    if (isalpha(LastChar)) {
        while (isalnum((LastChar + getchar()))) {
            lex::Lexer::IdentStr += LastChar;
            switch (lex::Lexer::token) {
                case 
            };
        }

    }
}