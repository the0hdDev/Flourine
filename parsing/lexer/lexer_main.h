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
            token_return = - 4,

            // primary
            token_identifier = -5,
            token_number = -6,


            // operators
            token_plus = -7,
            token_minus = -8,
            token_star = -9,
            token_slash = -10,
        };

        static char gettok(); 
        private:
        static std::string IdentStr;
        static double NumVal;

    };
}
