
#include "Lexer.h"
#include <cctype>

// Constructor
Lexer::Lexer(const std::string& source)
    : source(source) {

    keywords = {
        {"and", TokenType::AND},
        {"else", TokenType::ELSE},
        {"false", TokenType::FALSE},
        {"if", TokenType::IF},
        {"let", TokenType::LET},
        {"nil", TokenType::NIL},
        {"or", TokenType::OR},
        {"true", TokenType::TRUE},
        {"while", TokenType::WHILE},
        {"print", TokenType::PRINT}
    };
}

// Check if source has ended
bool Lexer::isAtEnd() {
    return current >= source.length();
}

// Read current character and advance
char Lexer::advance() {
    return source[current++];
}

// Add token to vector
void Lexer::addToken(TokenType type) {
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(type, text, line);
}

// Check if next character matches expected character
bool Lexer::match(char expected) {
    if (isAtEnd()) {
        return false;
    }

    if (source[current] != expected) {
        return false;
    }

    current++;
    return true;
}

// Return current character without advancing
char Lexer::peek() {
    if (isAtEnd()) {
        return '\0';
    }

    return source[current];
}

// Check digit
bool Lexer::isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Check letter or underscore
bool Lexer::isAlpha(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

// Check letter, digit, or underscore
bool Lexer::isAlphaNumeric(char c) {
    return isAlpha(c) || isDigit(c);
}

// Main scanning function
std::vector<Token> Lexer::scanTokens() {

    while (!isAtEnd()) {
        start = current;
        scanToken();
    }

    tokens.emplace_back(TokenType::END_OF_FILE, "", line);

    return tokens;
}

// Scan individual token
void Lexer::scanToken() {

    char c = advance();

    switch (c) {

        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;

        case '!':
            addToken(match('=') ?
                TokenType::BANG_EQUAL : TokenType::BANG);
            break;

        case '=':
            addToken(match('=') ?
                TokenType::EQUAL_EQUAL : TokenType::EQUAL);
            break;

        case '<':
            addToken(match('=') ?
                TokenType::LESS_EQUAL : TokenType::LESS);
            break;

        case '>':
            addToken(match('=') ?
                TokenType::GREATER_EQUAL : TokenType::GREATER);
            break;

        case '/':
            addToken(TokenType::SLASH);
            break;

        case ' ':
        case '\r':
        case '\t':
            break;

        case '\n':
            line++;
            break;

        case '"':
            string();
            break;

        default:
            if (isDigit(c)) {
                number();
            }
            else if (isAlpha(c)) {
                identifier();
            }
            else {
                // Ignore unrecognized characters
            }
            break;
    }
}

// Process string literals
void Lexer::string() {

    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') {
            line++;
        }

        advance();
    }

    if (isAtEnd()) {
        return;
    }

    // Consume closing quotation mark
    advance();

    addToken(TokenType::IDENTIFIER);
}

// Process numbers
void Lexer::number() {

    while (isDigit(peek())) {
        advance();
    }

    // Check for decimal numbers
    if (peek() == '.' && isDigit(source[current + 1])) {
        advance();

        while (isDigit(peek())) {
            advance();
        }
    }

    addToken(TokenType::NUMBER);
}

// Process identifiers and keywords
void Lexer::identifier() {

    while (isAlphaNumeric(peek())) {
        advance();
    }

    std::string text = source.substr(start, current - start);

    auto it = keywords.find(text);

    if (it != keywords.end()) {
        addToken(it->second);
    }
    else {
        addToken(TokenType::IDENTIFIER);
    }
}
