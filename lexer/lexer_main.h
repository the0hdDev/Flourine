#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <iostream>


namespace lex
{

    class Lexer
    {
    public:
        typedef enum token
        {
            tok_eof,
            tok_lparen,
            tok_lbrace,
            tok_rbrace,
            tok_comma,
            tok_plus,
            tok_minus,
            tok_star,
            tok_slash,
            tok_equal,
            tok_lessthan,
            tok_greaterthan,
            tok_period,
            tok_semicolon,
            tok_and,
            tok_or,
            tok_xor,
            tok_mod,
            tok_func,
            tok_return,
            tok_type,
            tok_string,
            tok_identifier,
            tok_number
        } Token;
    private:
        typedef struct location
        {
            size_t ln;
            size_t col;
        } Location;

        typedef struct token_data
        {
            Token type;
            std::string val;
            Location loc;
        } TokenData;

    public:
        typedef struct lexer
        {
            std::string start_tok;
            std::string cur_tok;
            TokenData* tokens;
            size_t line_num;
            std::string line_start;
            size_t token_count;
            size_t capacity;
        } Lexer_struct;
    };

    int lex(Lexer *lexer);
    void free_lex(Lexer *lexer);
    std::string token_to_str(lex::Lexer::Token token);
}