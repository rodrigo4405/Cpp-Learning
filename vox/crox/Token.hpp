#pragma once

#include "TokenType.hpp"

#include <string>
#include <any>

class Token {
    private:
        TokenType type;
        std::string lexeme;
        std::any literal;
        int line;

    public:
        Token(TokenType type, std::string lexeme, std::any literal, int line) {
            this->type = type;
            this->lexeme = lexeme;
            this->literal = literal;
            this->line = line;
        }

        /*
        std::string toString() {
            return type + " " + lexeme + " " + literal;
        }
        */
};