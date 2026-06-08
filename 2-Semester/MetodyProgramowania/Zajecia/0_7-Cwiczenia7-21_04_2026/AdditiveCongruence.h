#ifndef ADDITIVE_CONGRUENCE_H
#define ADDITIVE_CONGRUENCE_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "Utils.h"
#include "LCG.h"

using namespace std;

/**
 * @brief Tworzy liste rekomendowanych par indeksow dla addytywnej metody kongruencyjnej.
 * @return Vector par liczb calkowitych, gdzie first oznacza j, a second oznacza k.
 */
vector< pair< int, int > >createRecomendedPairListOfNumbers();

/**
 * @brief Wybiera pare indeksow j oraz k dla addytywnej metody kongruencyjnej.
 * @param n Rozmiar tablicy pamieci.
 * @return Wybrana para indeksow j oraz k albo para (-1, -1), jezeli nie znaleziono poprawnej pary.
 */
pair< int, int >choosePairForAdditiveCongruenceMethod( int n );

/**
 * @brief Tworzy tablice startowa X dla addytywnej metody kongruencyjnej.
 * @param n Rozmiar tablicy X.
 * @param m Modul generatora, czyli zakres wartosci od 0 do m - 1.
 * @return Vector X wypelniony liczbami wygenerowanymi przez LCG albo pusty vector, jezeli wystapil blad.
 */
vector< int >createStartTable_X_ForAdditiveCongruenceMethod( int n, int m );

/**
 * @brief Generuje liczby addytywna metoda kongruencyjna.
 * @param amountOfNumbers Liczba elementow do wygenerowania.
 * @param m Modul generatora, czyli zakres wartosci od 0 do m - 1.
 * @param Y Tablica pamieci, czyli odwrocona tablica X.
 * @param selectedPair Wybrana para indeksow j oraz k z tabeli rekomendowanych par.
 * @return Vector liczb wygenerowanych addytywna metoda kongruencyjna.
 */
vector< int >generate_numbers_by_AdditiveCongruenceMethod( int amountOfNumbers, int m, vector< int > Y, pair< int, int > selectedPair );

/**
 * @brief Glowny algorytm addytywnej metody kongruencyjnej.
 * @return Vector liczb wygenerowanych addytywna metoda kongruencyjna albo pusty vector, jezeli wystapil blad.
 */
vector< int >additiveCongruenceMethod();

#endif