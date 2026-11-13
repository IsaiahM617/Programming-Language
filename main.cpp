#include <iostream>
#include <string>
#include <vector>
#include "Lexer.h"

std::string typeName(TokenType t) {
    switch (t) {
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::DOT: return "DOT";
        case TokenType::MINUS: return "MINUS";
        case TokenType::PLUS: return "PLUS";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::SLASH: return "SLASH";
        case TokenType::STAR: return "STAR";
        case TokenType::BANG: return "BANG";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESS: return "LESS";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::AND: return "AND";
        case TokenType::ELSE: return "ELSE";
        case TokenType::FALSE: return "FALSE";
        case TokenType::IF: return "IF";
        case TokenType::LET: return "LET";
        case TokenType::NIL: return "NIL";
        case TokenType::OR: return "OR";
        case TokenType::TRUE: return "TRUE";
        case TokenType::WHILE: return "WHILE";
        case TokenType::PRINT: return "PRINT";
        case TokenType::END_OF_FILE: return "END_OF_FILE";
    }
    return "UNKNOWN";
}

int main() {
    std::string source =
        "let x = 10;\n"
        "let y = 3.5;\n"
        "print x + y * 2;\n"
        "if (x >= 10 and y != 0) print true;\n"
        "while (x < 20) { x = x + 1; }";

    Lexer lexer(source);
    std::vector<Token> tokens = lexer.scanTokens();

    for (const Token& token : tokens) {
        std::cout << "Line " << token.line
                  << " | " << typeName(token.type)
                  << " | '" << token.lexeme << "'"
                  << std::endl;
    }

    return 0;
}
