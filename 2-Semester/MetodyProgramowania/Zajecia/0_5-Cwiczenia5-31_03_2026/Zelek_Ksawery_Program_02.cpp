#include "Program_02_Algorytmy.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nazwaPliku;
    cout << "Podaj nazwe pliku tekstowego (Graf Nieskierowany): ";
    cin >> nazwaPliku;

    int liczbaWierzch = 0;
    
    // Budowanie tablicy list incydencji na podstawie struktur 
    Ogniwo** tablicaList = zbudujListeIncydencji( nazwaPliku, liczbaWierzch );

    if( tablicaList == nullptr )
    {
        cout << "Blad: Nie mozna otworzyc pliku lub plik jest pusty." << endl;
        return 1;
    }

    cout << "\n--- WYNIKI DLA GRAFU NIESKIEROWANEGO ---" << endl;

    // Wyswietlenie list incydencji 
    cout << "Tablica list incydencji:" << endl;
    for( int i = 0; i < liczbaWierzch; i++ )
    {
        cout << "[" << i + 1 << "]: ";
        Ogniwo* temp = tablicaList[ i ];
        while( temp != nullptr )
        {
            cout << temp->wierzcholek << " -> ";
            temp = temp->nastepny;
        }
        cout << "NULL" << endl;
    }

    cout << endl;

    // Wyznaczenie stopni wszystkich wierzcholkow 
    wyznaczStopnie( tablicaList, liczbaWierzch );

    zwolnijPamiec( tablicaList, liczbaWierzch );

    return 0;
}