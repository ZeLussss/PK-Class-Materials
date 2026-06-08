#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

/**
 * @brief Wypisuje jednowymiarowy vector liczb calkowitych.
 * @param arr Vector liczb calkowitych do wypisania.
 */
void printVector_INT_1D( vector< int > arr );

/**
 * @brief Odwraca kolejnosc elementow w jednowymiarowym vectorze liczb calkowitych.
 * @param arr Vector liczb calkowitych do odwrocenia.
 * @return Odwrocony vector liczb calkowitych.
 */
vector< int >reverseVector_INT_1D( vector< int > arr );

/**
 * @brief Sprawdza, czy uzytkownik wpisal poprawna liczbe calkowita.
 * @param nameOfVariable Nazwa zmiennej wyswietlana w komunikacie dla uzytkownika.
 * @return Poprawnie wprowadzona liczba calkowita.
 */
int checkCinStream( const string &nameOfVariable );

/**
 * @brief Sprawdza, czy liczba jest dodatnia.
 * @param number Liczba do sprawdzenia.
 * @param nameOfVariable Nazwa zmiennej wyswietlana w komunikacie bledu.
 * @return Poprawna liczba dodatnia.
 */
int checkIfPositive( const int &number, const string &nameOfVariable );

/**
 * @brief Oblicza najwiekszy wspolny dzielnik dwoch liczb.
 * @param a Pierwsza liczba calkowita.
 * @param b Druga liczba calkowita.
 * @return Najwiekszy wspolny dzielnik liczb a oraz b.
 */
int NWD( int a, int b );

/**
 * @brief Oblicza najmniejsza wspolna wielokrotnosc dwoch liczb.
 * @param a Pierwsza liczba calkowita.
 * @param b Druga liczba calkowita.
 * @return Najmniejsza wspolna wielokrotnosc liczb a oraz b.
 */
int NWW( int a, int b );

#endif