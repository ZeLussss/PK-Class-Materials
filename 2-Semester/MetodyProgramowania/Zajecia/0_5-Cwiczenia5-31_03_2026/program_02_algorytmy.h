#ifndef PROGRAM_02_ALGORYTMY_H
#define PROGRAM_02_ALGORYTMY_H

#include <string>
using namespace std;

/**
 * @brief Element listy jednokierunkowej przechowujący numer sąsiada. 
 */
struct Ogniwo 
{
    int wierzcholek;
    Ogniwo* nastepny;
};

Ogniwo** zbudujListeIncydencji( string nazwaPliku, int& liczbaWierzch );
void dodajKrawedz( Ogniwo** tablicaList, int u, int v );
void wyznaczStopnie( Ogniwo** tablicaList, int liczbaWierzch );
void zwolnijPamiec( Ogniwo** tablicaList, int liczbaWierzch );

#endif