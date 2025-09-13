#include <string>
#include <vector>

namespace lex 
{
    class Lexer {
        public: 
        enum Token {
            tok_eof = -1,

            // keywords
            token_func = -2,
            token_extern = -3,

            // primary
            token_identifier = -4,
            token_number = -5,

            // operators
            token_plus = -6,
            token_minus = -7,
            token_star = -8,
            token_slash = -9,
        };

        static char gettok(); 
        private:
        static std::string IdentStr;
        static double NumVal;

    };
}
