#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generujPodzbiory( int n, ofstream& outFile )
{
    int* B = new int[ n + 1 ];
    
    for( int k = 1; k <= n; k++ )
    {
        B[ k ] = 0;
    }

    int i = 0;
    int p = 1, j = 0;

    do
    {
        for( int k = 1; k <= n; k++ )
        {
            outFile << B[ k ];
        }
        outFile << "\n";

        i = i + 1;
        p = 1;
        j = i;

        while( j % 2 == 0 )
        {
            j = j / 2;
            p = p + 1;
        }

        if( p <= n )
        {
            B[ p ] = 1 - B[ p ];
        }

    } while( p <= n );

    delete[] B;
}

int main()
{
    string plikWejsciowy, plikWyjsciowy;
    int n;

    cout << "--- PROGRAM 01: PODZBIORY (KOD GRAYA) ---\n\n";
    cout << "Podaj nazwe pliku wejsciowego (zawierajacego n): ";
    cin >> plikWejsciowy;

    cout << "Podaj nazwe pliku wyjsciowego (np. lab3_1d.txt): ";
    cin >> plikWyjsciowy;

    ifstream inFile( plikWejsciowy );
    if( !inFile.is_open() )
    {
        cout << "Blad podczas otwierania pliku wejsciowego!\n";
        return 1;
    }

    if( !( inFile >> n ) )
    {
        cout << "Blad! Plik wejsciowy jest pusty lub ma zly format.\n";
        inFile.close();
        return 1;
    }
    inFile.close();

    ofstream outFile( plikWyjsciowy );
    if( !outFile.is_open() )
    {
        cout << "Blad podczas otwierania pliku wyjsciowego!\n";
        return 1;
    }

    cout << "Trwa generowanie podzbiorow...\n";
    generujPodzbiory( n, outFile );
    
    outFile.close();
    cout << "Zakonczono sukcesem! Zapisano do: " << plikWyjsciowy << "\n";

    return 0;
}