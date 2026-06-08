#ifndef PROGRAM_01_ALGORYTMY_H
#define PROGRAM_01_ALGORYTMY_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

/**
 * @brief Struktura przechowująca pojedynczą krawędź grafu skierowanego.
 */
struct Krawedz 
{
    int odWierzcholka;
    int doWierzcholka;
};

vector<Krawedz> wczytajKrawedzie( string nazwaPliku, int& liczbaKrawedzi, int& maxWierzch );
vector<vector<int>> utworzMacierzIncydencji( const vector<Krawedz>& krawedzie, int liczbaWierzcholkow );
void wypiszMacierz( const vector<vector<int>>& macierz );
void wyznaczSasiadow( const vector<Krawedz>& krawedzie, int liczbaWierzcholkow );

#endif