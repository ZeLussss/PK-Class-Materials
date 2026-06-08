#include <iostream>
#include <fstream> // Biblioteka do obslugi plikow
#include <string>
#include <stack>
#include "ArrayStack.h"
#include "LinkedListStack.h"

using namespace std;

int main()
{
    string fileName;
    cout << "Podaj nazwe pliku z danymi (np. wejscie.txt): ";
    cin >> fileName;

    ifstream inputFile( fileName );

    if( !inputFile.is_open() )
    {
        cout << "Blad: Nie mozna otworzyc pliku " << fileName << "!\n";
        return 1;
    }

    int n;
    if( !( inputFile >> n ) )
    {
        cout << "Blad: Nie udalo sie odczytac liczby elementow (n).\n";
        return 1;
    }

    ArrayStack sA( n ); 
    LinkedListStack sB;
    stack<int> sC;

    for( int i = 0; i < n; ++i )
    {
        int value;
        if( inputFile >> value )
        {
            sA.push( value );
            sB.push( value );
            sC.push( value );
        }
        else
        {
            cout << "Ostrzezenie: Plik zawiera mniej danych niz zadeklarowano.\n";
            break;
        }
    }

    inputFile.close();

    // --- Prezentacja wynikow ---
    cout << "Wypisywanie elementow (od szczytu):\n\n";

    cout << "Tablica dynamiczna jednowymiarowa: ";
    while( !sA.isEmpty() )
    {
        cout << sA.peek() << " ";
        sA.pop();
    }

    cout << "\nLista jednokierunkowa:   ";
    while( !sB.isEmpty() )
    {
        cout << sB.peek() << " ";
        sB.pop();
    }

    cout << "\nstd::stack:  ";
    while( !sC.empty() )
    {
        cout << sC.top() << " ";
        sC.pop();
    }
    cout << "\n";

    return 0;
}