#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generujKElementowe( int n, int k, ofstream& outFile )
{
    int* A = new int[ k + 1 ];
    
    for( int i = 1; i <= k; i++ )
    {
        A[ i ] = i;
    }

    int p = k;

    outFile << "n=" << n << "\n";
    outFile << "k=" << k << "\n\n";

    while( p >= 1 )
    {
        for( int i = 1; i <= k; i++ )
        {
            outFile << A[ i ];
        }
        outFile << "\n";

        if( A[ k ] == n )
        {
            p = p - 1;
        }
        else
        {
            p = k;
        }

        if( p >= 1 )
        {
            for( int i = k; i >= p; i-- )
            {
                A[ i ] = A[ p ] + i - p + 1;
            }
        }
    }

    delete[] A;
}

int main()
{
    string plikWejsciowy, plikWyjsciowy;
    int n, k;

    cout << "--- PROGRAM 02: PODZBIORY K-ELEMENTOWE ---\n\n";
    cout << "Podaj nazwe pliku wejsciowego (zawierajacego oddzielone spacja n oraz k): ";
    cin >> plikWejsciowy;

    cout << "Podaj nazwe pliku wyjsciowego (np. lab3_2d.txt): ";
    cin >> plikWyjsciowy;

    ifstream inFile( plikWejsciowy );
    if( !inFile.is_open() )
    {
        cout << "Blad podczas otwierania pliku wejsciowego!\n";
        return 1;
    }

    if( !( inFile >> n >> k ) )
    {
        cout << "Blad! Plik wejsciowy musi zawierac dwie liczby.\n";
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
    generujKElementowe( n, k, outFile );
    
    outFile.close();
    cout << "Zakonczono sukcesem! Zapisano do: " << plikWyjsciowy << "\n";

    return 0;
}