#include <iostream>
#include <string>
#include "Lib/LibTables.h"
#include "Lib/LibFiles.h"

using namespace std;

int main()
{
    string plikZnane, plikNieznane, plikWyjsciowy;

    cout << "--- IDENTYFIKACJA MODELU SILNIKA ---\n\n";
    cout << "Podaj nazwe pliku z siatkami identyfikacyjnymi (np. siatkaSEAK.txt): ";
    cin >> plikZnane;

    cout << "Podaj nazwe pliku z nieznanym modelem (np. nmSEAK.txt): ";
    cin >> plikNieznane;

    cout << "Podaj nazwe pliku wyjsciowego (np. wyniki.txt): ";
    cin >> plikWyjsciowy;
    
    cout << "\nPrzetwarzanie danych...\n\n";

    const int LICZBA_SIATEK = 81;
    const int LICZBA_KOLUMN = 106;

    double** siatkiZnane = alokujTablice( LICZBA_SIATEK * 2, LICZBA_KOLUMN );
    double** siatkaNieznana = alokujTablice( 2, LICZBA_KOLUMN );
    double* tablicaMSE = new double[ LICZBA_SIATEK ];

    // Wczytanie danych
    if( !wczytajDane( plikZnane, siatkiZnane, LICZBA_SIATEK * 2 ) )
    {
        cerr << "Blad wczytywania bazy siatek.\n";
        zwolnijTablice( siatkiZnane, LICZBA_SIATEK * 2 );
        zwolnijTablice( siatkaNieznana, 2 );
        delete[] tablicaMSE;
        
        return 1;
    }

    if( !wczytajDane( plikNieznane, siatkaNieznana, 2 ) )
    {
        cerr << "Blad wczytywania nieznanego modelu.\n";
        zwolnijTablice( siatkiZnane, LICZBA_SIATEK * 2 );
        zwolnijTablice( siatkaNieznana, 2 );
        delete[] tablicaMSE;
        
        return 1;
    }

    int indeksNajlepszy;
    double minMSE;

    // Obliczenia MSE za pomoca algorytmu
    znajdzNajlepszeDopasowanie( siatkiZnane, LICZBA_SIATEK, siatkaNieznana, tablicaMSE, indeksNajlepszy, minMSE );

    // Zapis wynikow
    if( zapiszWyniki( plikWyjsciowy, tablicaMSE, LICZBA_SIATEK, indeksNajlepszy, minMSE, siatkiZnane ) )
    {
        cout << "Zakonczono sukcesem!\n";
        cout << "Minimalny blad MSE: " << minMSE << " znaleziono dla siatki nr: " << ( indeksNajlepszy + 1 ) << "\n";
        cout << "Wyniki zapisano w pliku: " << plikWyjsciowy << "\n\n";
    }

    // Zwalnianie pamieci
    zwolnijTablice( siatkiZnane, LICZBA_SIATEK * 2 );
    zwolnijTablice( siatkaNieznana, 2 );
    delete[] tablicaMSE;

    return 0;
}