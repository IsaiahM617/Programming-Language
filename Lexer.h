
#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <string>
#include <vector>
#include <unordered_map>

class Lexer {
public:
    // Constructor
    Lexer(const std::string& source);

    // Scans source code and returns tokens
    std::vector<Token> scanTokens();

private:
    const std::string source;
    std::vector<Token> tokens;

    size_t start = 0;
    size_t current = 0;
    int line = 1;

    std::unordered_map<std::string, TokenType> keywords;

    bool isAtEnd();
    char advance();
    void addToken(TokenType type);
    bool match(char expected);
    char peek();

    void scanToken();
    void string();
    void number();
    void identifier();

    bool isDigit(char c);
    bool isAlpha(char c);
    bool isAlphaNumeric(char c);
};

#endif
