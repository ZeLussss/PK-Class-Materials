#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void wypiszPodzial( int* S, int* R, int d, ofstream& outFile )
{
    for( int i = 1; i <= d; i++ )
    {
        for( int count = 0; count < R[ i ]; count++ )
        {
            outFile << S[ i ] << " ";
        }
    }
    outFile << "\n";
}

void generujPodzialy( int n, ofstream& outFile )
{
    int* S = new int[ n + 1 ];
    int* R = new int[ n + 1 ];

    S[ 1 ] = n;
    R[ 1 ] = 1;
    int d = 1;

    outFile << n << "\n";
    wypiszPodzial( S, R, d, outFile );

    while( S[ 1 ] > 1 )
    {
        int sum = 0;
        
        if( S[ d ] == 1 )
        {
            sum = sum + R[ d ];
            d = d - 1;
        }

        sum = sum + S[ d ];
        R[ d ] = R[ d ] - 1;
        int l = S[ d ] - 1;

        if( R[ d ] > 0 )
        {
            d = d + 1;
        }

        S[ d ] = l;
        R[ d ] = sum / l;
        l = sum % l;

        if( l != 0 )
        {
            d = d + 1;
            S[ d ] = l;
            R[ d ] = 1;
        }

        wypiszPodzial( S, R, d, outFile );
    }

    delete[] S;
    delete[] R;
}

int main()
{
    string plikWejsciowy, plikWyjsciowy;
    int n;

    cout << "--- PROGRAM 03: PODZIALY LICZBY N ---\n\n";
    cout << "Podaj nazwe pliku wejsciowego (zawierajacego n): ";
    cin >> plikWejsciowy;

    cout << "Podaj nazwe pliku wyjsciowego (np. lab3_3d.txt): ";
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

    cout << "Trwa generowanie podzialow...\n";
    generujPodzialy( n, outFile );
    
    outFile.close();
    cout << "Zakonczono sukcesem! Zapisano do: " << plikWyjsciowy << "\n";

    return 0;
}