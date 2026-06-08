#include "Program_01_Algorytmy.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string nazwaPliku;
    cout << "Podaj nazwe pliku tekstowego (Graf Skierowany): ";
    cin >> nazwaPliku;

    int k = 0;        // Liczba krawedzi 
    int maxW = 0;     // Najwyzszy numer wierzcholka
    
    // Wczytanie krawedzi z pliku
    vector<Krawedz> krawedzie = wczytajKrawedzie( nazwaPliku, k, maxW );

    if( krawedzie.empty() )
    {
        cout << "Blad: Nie udalo sie wczytac danych lub graf jest pusty." << endl;
        return 1;
    }

    // Utworzenie macierzy incydencji przy uzyciu std::vector
    vector<vector<int>> macierz = utworzMacierzIncydencji( krawedzie, maxW );

    cout << "\n--- WYNIKI DLA GRAFU SKIEROWANEGO ---" << endl;
    
    // Wyswietlenie macierzy
    cout << "Macierz Incydencji:" << endl;
    for( int i = 0; i < maxW; i++ )
    {
        cout << "W" << i + 1 << ": ";
        for( int j = 0; j < k; j++ )
        {
            cout << macierz[ i ][ j ] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    // Wyznaczenie i wyswietlenie sasiadow 
    wyznaczSasiadow( krawedzie, maxW );

    return 0;
}