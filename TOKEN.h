#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum class TokenType {
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    IDENTIFIER,
    NUMBER,
    AND,
    ELSE,
    FALSE,
    IF,
    LET,
    NIL,
    OR,
    TRUE,
    WHILE,
    PRINT,
    END_OF_FILE
};

struct Token {
    TokenType type;
    string lexeme;
    int line;

    Token(TokenType type, const string& lexeme, int line)
        : type(type), lexeme(lexeme), line(line) {}
};

#endif
