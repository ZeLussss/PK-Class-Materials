#include <iostream>
#include <string>
#include <fstream>
#include "algorytmy.h"

using namespace std;

void uruchomProgram( const string& nazwaWejscia, const string& nazwaWyjscia )
{
    ifstream inFile( nazwaWejscia );
    ofstream outFile( nazwaWyjscia );

    if( !inFile.is_open() || !outFile.is_open() )
    {
        cout << "Blad podczas otwierania plikow wejscia/wyjscia!\n";
        cout << "Upewnij sie, ze podany plik wejsciowy (" << nazwaWejscia << ") istnieje.\n";
        return;
    }

    int z;
    if( !( inFile >> z ) ) return; 

    while( z-- )
    {
        int n;
        inFile >> n;

        long long* numbers = new long long[ n ];

        for( int i = 0; i < n; i++ )
        {
            long long temp;
            inFile >> temp;
            numbers[ i ] = temp;
        }

        przetworzZestaw( inFile, outFile, numbers, n );

        delete[] numbers;
    }

    inFile.close(); 
    outFile.close();
}

int main()
{
    string plikWejsciowy, plikWyjsciowy;

    cout << "--- LABORATORIUM 3: METODY PROGRAMOWANIA ---\n\n";
    
    cout << "Podaj nazwe pliku wejsciowego z danymi (np. wejscie.txt): ";
    cin >> plikWejsciowy;

    cout << "Podaj nazwe pliku wyjsciowego (np. wyjscie.txt): ";
    cin >> plikWyjsciowy;
    
    cout << "\nPrzetwarzanie danych...\n\n";

    uruchomProgram( plikWejsciowy, plikWyjsciowy );
    
    cout << "Zakonczono! Jesli nie bylo bledow, wyniki zapisano w pliku: " << plikWyjsciowy << "\n\n";
    
    return 0;
}