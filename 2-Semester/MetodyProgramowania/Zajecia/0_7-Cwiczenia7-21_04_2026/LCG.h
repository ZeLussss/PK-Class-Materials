#ifndef LCG_H
#define LCG_H

#include <iostream>
#include <string>
#include <vector>

#include "Utils.h"

using namespace std;

/**
 * @brief Rozklada liczbe na unikalne czynniki pierwsze.
 * @param m Liczba, ktora ma zostac rozlozona na czynniki pierwsze.
 * @return Vector unikalnych czynnikow pierwszych liczby m.
 */
vector< int >uniquePrimeFactors( int m );

/**
 * @brief Szuka wspolczynnika a dla liniowego generatora kongruencyjnego.
 * @param m Modul generatora LCG.
 * @return Znaleziony wspolczynnik a albo -1, jezeli nie znaleziono poprawnej wartosci.
 */
int find_A_For_LCG( int m );

/**
 * @brief Generuje liczby za pomoca liniowego generatora kongruencyjnego.
 * @param n Liczba elementow do wygenerowania.
 * @param m Modul generatora, czyli zakres wartosci od 0 do m - 1.
 * @param X_0 Ziarno generatora, czyli wartosc poczatkowa.
 * @param a Mnoznik generatora LCG.
 * @param c Przyrost generatora LCG.
 * @return Vector liczb wygenerowanych metoda LCG.
 */
vector< int >generate_numbers_by_LCG( int n, int m, int X_0, int a, int c );

/**
 * @brief Glowny algorytm liniowego generatora kongruencyjnego.
 * @return Vector liczb wygenerowanych metoda LCG albo pusty vector, jezeli wystapil blad.
 */
vector< int >LCG_Algorithm();

#endif