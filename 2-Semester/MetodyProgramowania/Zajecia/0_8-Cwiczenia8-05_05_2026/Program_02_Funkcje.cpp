// Autor: Ksawery Zelek

#include "Program_02_Funkcje.h"

using namespace std;

// Implementacja funkcji rekurencyjnej szukaj
bool szukaj( int cel, int index, const vector< int > &elementy, string &wynik )
{
    // SUKCES
    if( cel == 0 )
    {
        return true;
    }

    // PORAŻKA
    if( index >=  ( int )elementy.size() || cel < 0 )
    {
        return false;
    }

    // REKURENCJA
    if( szukaj( cel - elementy[ index ], index + 1, elementy, wynik ) )
    {
        string separator = ( wynik.empty() ? "" : " " );

        wynik = to_string( elementy[ index ] ) + separator + wynik;
        
        return true;
    }

    return szukaj( cel, index + 1, elementy, wynik );
}

// Implementacja funkcji rozwiazProblem
string rozwiazProblem( const vector< int > &arr, int cel )
{
    string wynik = "";

    try
    {
        if( szukaj( cel, 0, arr, wynik ) )
        {
            return ( to_string( cel ) + " = " + wynik );
        }
        else
        {
            return "BRAK";
        }
    }
    catch( ... )
    {
        throw;
    }
}