// Autor: Ksawery Zelek

#pragma once
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Funkcja rekurencyjna podejmująca próbę dopasowania wag elementów do celu.
 * 
 * @param cel Aktualnie poszukiwana suma.
 * @param index Index aktualnie rozważanego elementu ze zbioru.
 * @param elementy Wektor wag dostępnych elementów.
 * @param wynik Referencja do stringa, który przechowuje rozwiązanie.
 * @return true, jeśli suma wag wybranych elementów jest równa wadze docelowej; false w przeciwnym razie.
 */
bool szukaj( int cel, int index, const vector< int > &elementy, string &wynik );

/**
 * @brief Funkcja przygotowująca sformatowane wyjście programu.
 * 
 * @param arr Wektor wejściowy wag wszystkich dostępnych elementów.
 * @param cel Docelowa sumaryczna waga plecaka.
 * @return Sformatowany ciąg znaków zgodny ze specyfikacją wyjścia.
 */
string rozwiazProblem( const vector< int > &arr, int cel );