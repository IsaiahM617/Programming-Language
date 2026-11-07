#ifndef TOKEN_H
#define TOKEN_H

struct Token {
    TokenType type;
    string lexeme;    
    int line;        

    Token(TokenType type, const string& lexeme, int line)
        : type(type), lexeme(lexeme), line(line) {}
};
#endif
