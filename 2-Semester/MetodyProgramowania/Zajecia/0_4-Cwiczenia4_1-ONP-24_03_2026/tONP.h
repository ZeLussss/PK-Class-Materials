#ifndef TONP_H
#define TONP_H

#include <string>

// Funkcje pomocnicze do weryfikacji znakow i operatorow
bool isOperand( char c );
int priority( char c );
bool isRightAssociative( char c );
bool isOperator( char c );

// Czyszczenie i walidacja wyrazen
std::string cleanExpression( const std::string& s, bool isINF );
bool isValidINF( const std::string& s );
bool isValidONP( const std::string& s );

// Glowne funkcje konwertujace
std::string infToOnp( const std::string& inf );
std::string onpToInf( const std::string& onp );

#endif // TONP_H