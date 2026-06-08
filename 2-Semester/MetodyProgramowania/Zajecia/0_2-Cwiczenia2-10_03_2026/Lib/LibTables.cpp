#include "LibTables.h"
#include <cmath>

using namespace std;

double** alokujTablice( int wiersze, int kolumny )
{
    double** tablica = new double*[ wiersze ];

    for( int i = 0; i < wiersze; ++i )
    {
        tablica[ i ] = new double[ kolumny ];
    }

    return tablica;
}

void zwolnijTablice( double** tablica, int wiersze )
{
    for( int i = 0; i < wiersze; ++i )
    {
        delete[] tablica[ i ];
    }

    delete[] tablica;
}

double obliczMSE( double* Y_znane, double* X_znane, double* Y_nieznane, double* X_nieznane, int liczbaDanych )
{
    double sumaY = 0.0;
    double sumaX = 0.0;

    // Wspolrzedne wektorow X i Y zaczynaja sie od indeksu 6
    int startIdx = 6;

    for( int i = 0; i < liczbaDanych; ++i )
    {
        double diffY = Y_znane[ startIdx + i ] - Y_nieznane[ startIdx + i ];
        sumaY += ( diffY * diffY );

        double diffX = X_znane[ startIdx + i ] - X_nieznane[ startIdx + i ];
        sumaX += ( diffX * diffX );
    }

    return sqrt( sumaY + sumaX );
}

void znajdzNajlepszeDopasowanie( double** siatkiZnane, int liczbaSiatek, double** siatkaNieznana, double* tablicaMSE, int& indeksNajlepszy, double& minMSE )
{
    // Inicjalizacja duza wartoscia
    minMSE = 1e9; 
    indeksNajlepszy = -1;

    for( int i = 0; i < liczbaSiatek; ++i )
    {
        // Obliczenie MSE dla danej pary
        double currentMSE = obliczMSE( siatkiZnane[ 2 * i ], siatkiZnane[ 2 * i + 1 ], 
                                       siatkaNieznana[ 0 ], siatkaNieznana[ 1 ], 100 );
        
        tablicaMSE[ i ] = currentMSE;

        // Wyszukiwanie minimum recznie
        if( currentMSE < minMSE )
        {
            minMSE = currentMSE;
            indeksNajlepszy = i;
        }
    }
}