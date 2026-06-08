// Autor: Ksawery Zelek

#pragma once
#include <vector>

/**
 * @brief Wypisuje zawartosc tablicy 2D w konsoli.
 */
void printVectorTab_2D( const std::vector< std::vector <int> >& arr );

/**
 * @brief Rekurencyjne wyszukiwanie binarne - pierwsze wystąpienie w wierszu.
 */
int binSearchFirstRec( const std::vector <int>& row, int target, int L, int R );

/**
 * @brief Rekurencyjne wyszukiwanie binarne - ostatnie wystąpienie w wierszu.
 */
int binSearchLastRec( const std::vector <int>& row, int target, int L, int R );

/**
 * @brief 1. Funkcja rekurencyjna wyznaczajaca pierwsze wystapienie elementu.
 */
void f_rekPier( const std::vector< std::vector <int> >& arr, int target, int row );

/**
 * @brief 2. Funkcja rekurencyjna wyznaczajaca ostatnie wystapienie elementu.
 */
void f_rekOst( const std::vector< std::vector <int> >& arr, int target, int row );

/**
 * @brief 3. Funkcja iteracyjna wyznaczajaca pierwsze wystapienie elementu.
 */
void f_iterPier( const std::vector< std::vector <int> >& arr, int target );

/**
 * @brief 4. Funkcja iteracyjna wyznaczajaca ostatnie wystapienie elementu.
 */
void f_iterOst( const std::vector< std::vector <int> >& arr, int target );