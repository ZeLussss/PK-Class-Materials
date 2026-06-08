#include "LibFiles.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool wczytajDane( const string& nazwaPliku, double** tablica, int liczbaWierszy )
{
    ifstream plik( nazwaPliku );

    if( !plik.is_open() )
    {
        cerr << "Blad: Nie mozna otworzyc pliku " << nazwaPliku << "\n";
        return false;
    }

    string linia;
    int wczytaneWiersze = 0;

    while( getline( plik, linia ) && wczytaneWiersze < liczbaWierszy )
    {
        // Zamiana przecinkow na kropki
        for( size_t i = 0; i < linia.length(); ++i )
        {
            if( linia[ i ] == ',' )
            {
                linia[ i ] = '.';
            }
        }
        
        stringstream ss( linia );
        string token;
        int indeksKolumny = 0;

        // Wczytujemy maksymalnie 106 kolumn: 6 parametrow i 100 wartosci wektora
        while( ss >> token && indeksKolumny < 106 )
        {
            // Pomijamy znane etykiety tekstowe
            if( token == "Y" || token == "X" || token == "Model" || token == "kp" || 
                token == "Tz" || token == "T1" || token == "T2" || token == "T" || 
                token == "L" || token == "R" || token == "J" )
            {
                continue;
            }

            // Weryfikacja, czy token jest liczbą
            if( ( token[ 0 ] >= '0' && token[ 0 ] <= '9' ) || token[ 0 ] == '-' )
            {
                tablica[ wczytaneWiersze ][ indeksKolumny ] = stod( token );
                indeksKolumny++;
            }
        }

        // Akceptacja wiersza
        if( indeksKolumny >= 106 )
        {
            wczytaneWiersze++;
        }
    }

    plik.close();
    
    return ( wczytaneWiersze == liczbaWierszy );
}

bool zapiszWyniki( const string& nazwaPliku, double* tablicaMSE, int liczbaSiatek, int indeksNajlepszy, double minMSE, double** siatkiZnane )
{
    ofstream plik( nazwaPliku );

    if( !plik.is_open() )
    {
        cerr << "Blad: Nie mozna utworzyc pliku wyjsciowego " << nazwaPliku << "\n";
        return false;
    }

    plik << "Wartosci bledow mse dla kazdej z siatek:\n";

    for( int i = 0; i < liczbaSiatek; ++i )
    {
        plik << tablicaMSE[ i ] << " ";
        
        if( ( i + 1 ) % 10 == 0 )
        {
            plik << "\n";
        }
    }

    plik << "\n\nMinimalny bled mse: " << minMSE << "\n\n";
    plik << "Wektor Y,X z wszystkimi danymi najlepszego dopasowania:\n";

    // Zapis wiersza Y dla najlepszego dopasowania
    for( int i = 0; i < 106; ++i )
    {
        plik << siatkiZnane[ 2 * indeksNajlepszy ][ i ] << " ";
        
        if( ( i + 1 ) % 7 == 0 )
        {
            plik << "\n";
        }
    }
    
    plik << "\n\n";

    // Zapis wiersza X dla najlepszego dopasowania
    for( int i = 0; i < 106; ++i )
    {
        plik << siatkiZnane[ 2 * indeksNajlepszy + 1 ][ i ] << " ";
        
        if( ( i + 1 ) % 7 == 0 )
        {
            plik << "\n";
        }
    }

    plik.close();
    
    return true;
}