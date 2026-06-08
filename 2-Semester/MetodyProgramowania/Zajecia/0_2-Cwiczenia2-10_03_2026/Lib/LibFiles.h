#ifndef LIBFILES_H
#define LIBFILES_H

#include <string>

using namespace std;

/**
 * Funkcja wczytuje dane z pliku tekstowego do dwuwymiarowej tablicy dynamicznej.
 * Wlasnorecznie zamienia przecinki na kropki w obrebie wczytanej linii,
 * aby poprawnie konwertowac typ string na liczbe zmiennoprzecinkowa.
 */
bool wczytajDane( const string& nazwaPliku, double** tablica, int liczbaWierszy );

/**
 * Funkcja zapisuje wyniki (tablice bledow MSE, minimalny blad oraz wektory Y i X) 
 * do podanego przez uzytkownika pliku wyjsciowego.
 */
bool zapiszWyniki( const string& nazwaPliku, double* tablicaMSE, int liczbaSiatek, int indeksNajlepszy, double minMSE, double** siatkiZnane );

#endif