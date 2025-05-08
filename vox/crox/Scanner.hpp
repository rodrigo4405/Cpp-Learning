#include "Token.hpp"
#include "TokenType.hpp"
#include "Crox.hpp"

using namespace Lox;

#include <string>
#include <vector>

namespace Lox {
    class Scanner {
        private:
            std::string source;
            std::vector<Token> tokens;

            int start = 1;
            int current = start;
            int line = 1;

            bool isAtEnd() {
                return current >= source.size();
            }

            char advance() {
                return source.at(current++);
            }

            // addToken is overloaded :)

            void addToken(TokenType type, std::any literal) {
                std::string text = source.substr(start, current);

                Token newToken = Token(type, text, literal, line);
                tokens.push_back(newToken);
            }

            void addToken(TokenType type) {
                addToken(type, NULL);
            }

            void scanToken() {
                char c = advance();

                switch (c) {
                    case '(': addToken(LEFT_PAREN); break;
                    case ')': addToken(RIGHT_PAREN); break;
                    case '{': addToken(LEFT_BRACE); break;
                    case '}': addToken(RIGHT_BRACE); break;
                    case ',': addToken(COMMA); break;
                    case '.': addToken(DOT); break;
                    case '-': addToken(MINUS); break;
                    case '+': addToken(PLUS); break;
                    case ';': addToken(SEMICOLON); break;
                    case '*': addToken(STAR); break;
                    default:
                        // (Crox.cpp) Lox::error
                        error(line, "Unexpected character.");
                        break;
                  }
              
            }
        
        public:
            Scanner(std::string source) {
                this->source = source;
            }

            std::vector<Token> scanTokens() {
                while (!isAtEnd()) {
                    start = current;
                    scanToken();
                }

                Token newToken = Token(EOF_, "", NULL, line);
                tokens.push_back(newToken);

                return tokens;
            }
    };
}