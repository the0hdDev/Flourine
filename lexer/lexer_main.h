#include <string>
#include <vector>

namespace lex 
{
    class Lexer {
        public: 
        enum token {
            token_eof = -1,
            // commands
            token_func = -2,
            token_extern = -3, 
            // primary
            token_indentifier = -4,
        };
        static char gettok(); 
        private:
        static std::string IdentStr;
        static double NumVal;



    }
}