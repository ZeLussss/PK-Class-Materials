// Autor: Ksawery Zelek
#include "Huffman.h"
#include <iostream>
#include <vector>
#include <utility>
#include <exception>

using namespace std;

// ==================================================================================================================
int main()
{
    try
    {
        // Dane z tabeli a)
        vector< pair< char, double > > daneA =
        {
            { 'A', 12 },
            { 'B', 7 },
            { 'I', 18 },
            { 'M', 10 },
            { 'S', 9 },
            { 'X', 5 },
            { 'Z', 2 }
        };

        // Dane z tabeli b)
        vector< pair< char, double > > daneB =
        {
            { 'c', 0.11 },
            { 'e', 0.22 },
            { 'i', 0.16 },
            { 'r', 0.12 },
            { 's', 0.15 },
            { 't', 0.10 },
            { 'x', 0.14 }
        };

        cout << "Tabela a)\n";
        buildTree( daneA );

        cout << "Tabela b)\n";
        buildTree( daneB );
    }
    catch( const HuffmanException& e )
    {
        cerr << "Blad Huffmana: " << e.what() << "\n";
        return 1;
    }
    catch( const exception& e )
    {
        cerr << "Blad programu: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

// ==================================================================================================================
