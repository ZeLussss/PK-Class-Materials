// Autor: Ksawery Zelek
#include "Huffman.h"
#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;

// ==================================================================================================================
// Stworzenie wlasnej klasy wyjatkow dla programu
HuffmanException::HuffmanException( const string& message ) : runtime_error( message ) {}

// ==================================================================================================================
// Stworzenie komparatora dla prirytetowej kolejki
bool compare::operator()( pair< double, string > l, pair< double, string > r )
{
    if( l.first == r.first )
    {
        return l.second > r.second;
    }
    return l.first > r.first;
}

// ==================================================================================================================
// Analiza stworzonego kodu Huffmana
void analizaTekstu( vector< pair< char, double > > dane, unordered_map< char, string >& huffman, unordered_map< char, double >& iloscLiter )
{
    double klasycznyZapis = 0;
    double ASCII = 0;
    double czteryBit = 0;
    double huffmanIleBit = 0;
    double suma = 0;

    for( auto i : dane )
    {
        if( huffman.find( i.first ) == huffman.end() )
        {
            throw HuffmanException( "Brak kodu Huffmana dla symbolu." );
        }

        suma += iloscLiter[ i.first ];
        huffmanIleBit += ( iloscLiter[ i.first ] * huffman[ i.first ].length() );
    }

    if( suma <= 0 )
    {
        throw HuffmanException( "Suma czestotliwosci lub prawdopodobienstwa musi byc wieksza od zera." );
    }

    klasycznyZapis = suma * 8;
    ASCII = suma * 7;
    czteryBit = suma * 4;

    double klasycznyZapisProcenty = 100;
    double ASCII_Procenty = ( ASCII / klasycznyZapis ) * 100;
    double czteryBitProcenty = ( czteryBit / klasycznyZapis ) * 100;
    double huffmanBitProcenty = ( huffmanIleBit / klasycznyZapis ) * 100;

    cout << "\n---------------------\n";
    cout << "Klasyczny zapis -> " << fixed << setprecision( 1 ) << klasycznyZapis << "(" << klasycznyZapisProcenty << "%)\n";
    cout << "ASCII -> " << fixed << setprecision( 1 ) << ASCII << "(" << ASCII_Procenty << "%)\n";
    cout << "CzteryBit -> " << fixed << setprecision( 1 ) << czteryBit << "(" << czteryBitProcenty << "%)\n";
    cout << "Huffman -> " << fixed << setprecision( 1 ) << huffmanIleBit << "(" << huffmanBitProcenty << "%)\n";
    cout << "---------------------\n\n";
}

// ==================================================================================================================
void buildTree( vector< pair< char, double > > dane )
{
    if( dane.empty() )
    {
        throw HuffmanException( "Brak danych wejsciowych." );
    }

    // Obliczanie ilosci wystepowania liter lub ich prawdopodobienstwa
    unordered_map< char, double > iloscLiter;
    for( auto i : dane )
    {
        if( i.second <= 0 )
        {
            throw HuffmanException( "Czestotliwosc lub prawdopodobienstwo musi byc wieksze od zera." );
        }

        if( iloscLiter.find( i.first ) != iloscLiter.end() )
        {
            throw HuffmanException( "Powtorzony symbol w danych wejsciowych." );
        }

        iloscLiter[ i.first ] = i.second;
    }

    // Stworzenie priorytetowej kolejki dla galezi drzewa huffmana
    priority_queue< pair< double, string >, vector< pair< double, string > >, compare > pq;

    // Dodanie kazdego znaku i jego ilosci wystepowania lub prawdopodobienstwa do kolejki
    for( auto i : iloscLiter )
    {
        pq.push( { i.second, string( 1, i.first ) } );
    }

    // Stworzenie mapy przechowujacej poszczegolne galezie
    unordered_map< char, string > huffman;

    if( pq.size() == 1 )
    {
        huffman[ pq.top().second[ 0 ] ] = "0";
    }

    while( pq.size() > 1 )
    {
        // Dwie pary o najmniejszej czestotliwosci lub prawdopodobienstwie
        auto left = pq.top(); pq.pop();
        auto right = pq.top(); pq.pop();

        // Aktualizacja
        for( char ch : left.second )
        {
            huffman[ ch ] = "0" + huffman[ ch ];
        }
        for( char ch : right.second )
        {
            huffman[ ch ] = "1" + huffman[ ch ];
        }

        // Laczenie dwoch par i dodanie do kolejki
        string noweDrzewo = left.second + right.second;
        sort( noweDrzewo.begin(), noweDrzewo.end() );
        pq.push( { left.first + right.first, noweDrzewo } );
    }

    // Posortowanie wynikow do wypisania
    vector< pair< char, string > > wynik;
    for( auto i : huffman )
    {
        wynik.push_back( { i.first, i.second } );
    }

    sort( wynik.begin(), wynik.end() );

    cout << "Drzewo:\n";
    for( auto i : wynik )
    {
        cout << i.first << " " << i.second << "\n";
    }

    // Stworzenie zakodowanego tekstu
    string encodedString = "";
    for( auto i : dane )
    {
        encodedString += huffman[ i.first ];
    }

    cout << "\nZakodowany tekst: " << encodedString << "\n";

    analizaTekstu( dane, huffman, iloscLiter );
}

// ==================================================================================================================
