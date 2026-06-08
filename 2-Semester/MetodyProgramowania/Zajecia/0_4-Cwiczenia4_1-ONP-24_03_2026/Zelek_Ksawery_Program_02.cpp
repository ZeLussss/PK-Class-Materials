#include <iostream>
#include <fstream>
#include <string>
#include "tONP.h"

using namespace std;

int main() 
{
    string fileName;
    
    cout << "Podaj nazwe pliku z danymi (np. dane.txt): ";
    cin >> fileName;

    ifstream inputFile( fileName );

    if( !inputFile.is_open() )
    {
        cout << "Blad: Nie mozna otworzyc pliku o nazwie " << fileName << "!\n";
        return 1;
    }

    int n;
    
    if( !( inputFile >> n ) ) 
    {
        cout << "Blad: Nie udalo sie odczytac liczby wyrazow (n).\n";
        return 1;
    }
    
    string line;
    getline( inputFile, line ); 

    for( int i = 0; i < n; ++i )
    {
        getline( inputFile, line );
        
        if( line.empty() )
        {
            i--;
            continue;
        }

        bool isINF = false;
        size_t pos = 0;

        // Sprawdzenie jakiego typu jest wyrazenie w danej linii
        if( ( pos = line.find( "INF:" ) ) != string::npos )
        {
            isINF = true;
            pos += 4; // Przesuniecie za napis "INF:"
        }
        else if( ( pos = line.find( "ONP:" ) ) != string::npos )
        {
            isINF = false;
            pos += 4;
        }
        else
        {
            continue; 
        }

        string rawExpr = line.substr( pos );
        string cleaned = cleanExpression( rawExpr, isINF );

        if( isINF )
        {
            if( isValidINF( cleaned ) )
            {
                cout << "ONP: " << infToOnp( cleaned ) << "\n";
            }
            else
            {
                cout << "ONP: error\n";
            }
        }
        else
        {
            if( isValidONP( cleaned ) )
            {
                cout << "INF: " << onpToInf( cleaned ) << "\n";
            }
            else
            {
                cout << "INF: error\n";
            }
        }
    }
    
    inputFile.close();
    
    return 0;
}