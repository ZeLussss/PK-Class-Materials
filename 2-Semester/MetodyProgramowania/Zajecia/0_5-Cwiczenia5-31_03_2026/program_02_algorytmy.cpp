#include "Program_02_Algorytmy.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Dodaje krawędź do listy incydencji (graf nieskierowany). 
 */
void dodajKrawedz( Ogniwo** tablicaList, int u, int v )
{
    // Dodanie v do listy wierzchołka u
    Ogniwo* noweU = new Ogniwo;
    noweU->wierzcholek = v;
    noweU->nastepny = tablicaList[ u - 1 ];
    tablicaList[ u - 1 ] = noweU;

    // Dodanie u do listy wierzchołka v (graf nieskierowany)
    Ogniwo* noweV = new Ogniwo;
    noweV->wierzcholek = u;
    noweV->nastepny = tablicaList[ v - 1 ];
    tablicaList[ v - 1 ] = noweV;
}

/**
 * @brief Tworzy tablicę list incydencji na podstawie pliku.
 */
Ogniwo** zbudujListeIncydencji( string nazwaPliku, int& liczbaWierzch )
{
    ifstream plik( nazwaPliku );
    if( !plik.is_open() ) return nullptr;

    int k;
    plik >> k; // Liczba krawędzi

    // Wstępne rozpoznanie liczby wierzchołków
    liczbaWierzch = 0;
    struct Para { int a, b; };
    Para* krawedzieTemp = new Para[ k ];

    for( int i = 0; i < k; i++ )
    {
        plik >> krawedzieTemp[ i ].a >> krawedzieTemp[ i ].b;
        if( krawedzieTemp[ i ].a > liczbaWierzch ) liczbaWierzch = krawedzieTemp[ i ].a;
        if( krawedzieTemp[ i ].b > liczbaWierzch ) liczbaWierzch = krawedzieTemp[ i ].b;
    }

    Ogniwo** tablicaList = new Ogniwo*[ liczbaWierzch ];
    for( int i = 0; i < liczbaWierzch; i++ ) tablicaList[ i ] = nullptr;

    for( int i = 0; i < k; i++ )
    {
        dodajKrawedz( tablicaList, krawedzieTemp[ i ].a, krawedzieTemp[ i ].b );
    }

    delete[] krawedzieTemp;
    plik.close();
    return tablicaList;
}

/**
 * @brief Wyznacza stopnie wszystkich wierzchołków grafu. 
 * Stopień to liczba elementów na liście incydencji danego wierzchołka.
 */
void wyznaczStopnie( Ogniwo** tablicaList, int liczbaWierzch )
{
    cout << "Stopnie wierzcholkow:" << endl;
    for( int i = 0; i < liczbaWierzch; i++ )
    {
        int stopien = 0;
        Ogniwo* temp = tablicaList[ i ];
        while( temp != nullptr )
        {
            stopien++;
            temp = temp->nastepny;
        }
        cout << "Wierzcholek " << i + 1 << ": stopien " << stopien << endl;
    }
}

/**
 * @brief Zwalnia pamiec zajeta przez tablice list incydencji.
 * Przechodzi przez kazde ogniwo listy i usuwa je z pamieci.
 */
void zwolnijPamiec( Ogniwo** tablicaList, int liczbaWierzch )
{
    for( int i = 0; i < liczbaWierzch; i++ )
    {
        Ogniwo* aktualny = tablicaList[ i ];
        while( aktualny != nullptr )
        {
            Ogniwo* doUsuniecia = aktualny;
            aktualny = aktualny->nastepny;
            delete doUsuniecia; // Usuniecie pojedynczego ogniwa
        }
    }
    delete[] tablicaList; // Usuniecie samej tablicy wskaznikow
}