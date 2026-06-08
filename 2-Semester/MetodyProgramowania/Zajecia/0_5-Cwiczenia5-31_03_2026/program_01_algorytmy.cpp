#include "Program_01_Algorytmy.h"
#include <iostream>

using namespace std;

/**
 * @brief Wczytuje definicje krawędzi z pliku tekstowego. 
 * Zwraca wektor krawędzi oraz aktualizuje liczbę krawędzi i najwyższy numer wierzchołka.
 */
vector<Krawedz> wczytajKrawedzie( string nazwaPliku, int& liczbaKrawedzi, int& maxWierzch )
{
    ifstream plik( nazwaPliku );
    vector<Krawedz> krawedzie;
    maxWierzch = 0;

    if( plik.is_open() )
    {
        plik >> liczbaKrawedzi; // Pierwsza linia: liczba krawędzi k
        for( int i = 0; i < liczbaKrawedzi; i++ )
        {
            int u, v;
            plik >> u >> v; // Pary liczb: wyjściowy i docelowy 
            krawedzie.push_back( { u, v } );
            if( u > maxWierzch ) maxWierzch = u;
            if( v > maxWierzch ) maxWierzch = v;
        }
        plik.close();
    }
    return krawedzie;
}

/**
 * @brief Tworzy macierz incydencji dla grafu skierowanego. 
 */
vector<vector<int>> utworzMacierzIncydencji( const vector<Krawedz>& krawedzie, int liczbaWierzcholkow )
{
    // Macierz: wiersze = wierzchołki, kolumny = krawędzie 
    vector<vector<int>> macierz( liczbaWierzcholkow, vector<int>( krawedzie.size(), 0 ) );

    for( int j = 0; j < ( int )krawedzie.size(); j++ )
    {
        int u = krawedzie[ j ].odWierzcholka - 1; 
        int v = krawedzie[ j ].doWierzcholka - 1;
        
        macierz[ u ][ j ] = 1;  // Wierzchołek wyjściowy 
        macierz[ v ][ j ] = -1; // Wierzchołek docelowy 
    }
    return macierz;
}

/**
 * @brief Wyznacza i wypisuje sąsiadów dla każdego wierzchołka. 
 */
void wyznaczSasiadow( const vector<Krawedz>& krawedzie, int liczbaWierzcholkow )
{
    for( int i = 1; i <= liczbaWierzcholkow; i++ )
    {
        cout << "Wierzcholek " << i << " ma sasiadow: ";
        for( const auto& k : krawedzie )
        {
            if( k.odWierzcholka == i ) cout << k.doWierzcholka << " ";
        }
        cout << endl;
    }
}