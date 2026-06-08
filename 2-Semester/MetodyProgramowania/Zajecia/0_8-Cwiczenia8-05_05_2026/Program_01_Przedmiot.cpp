// Autor: Ksawery Zelek

#include "Program_01_Przedmiot.h"
#include <iostream>
#include <iomanip>
using namespace std;

static string line( 45, '-' );

void printInventory( const vector< Przedmiot > &inv )
{
    cout << "\n" << line << "\n";

    for( auto i : inv )
    {
        cout << "| " << i.nazwa << " | " << i.masa << " | " << i.cena << " |\n"; 
    }

    cout << line << "\n\n";
}

void printWeight_ALL( const vector< Przedmiot > &inv, int m_max, int n )
{
    string dynamicLine( ( m_max + 2 ) * 7 - 7, '-' );

    cout << "Tabela wag (P):\n";
    cout << dynamicLine << "\n";
    
    cout << "| " << setw( 4 ) << " " << " ";
    for( int i = 1; i <= m_max; i++ )
    {
        cout << "| " << setw( 4 ) << i << " ";
    }   cout << "|\n";
    
    for( int i = 1; i <= n; i++ )
    {
        cout << "| " << setw( 4 ) << i << " | ";

        for( int j = 1; j <= m_max; j++ )
        {
            cout << setw( 4 ) << inv[ i - 1 ].capacityBackpack[ j ] << " | ";
        }   cout << "\n";
    }

    cout << dynamicLine << "\n\n";
}

void printIndex_ALL( const vector< Przedmiot > &inv, int m_max, int n )
{
    string dynamicLine( ( m_max + 2 ) * 7 - 7, '-' );

    cout << "TABELA INDEKSOW (Q):\n";
    cout << dynamicLine << "\n";
    
    cout << "| " << setw( 4 ) << " " << " ";
    for( int i = 1; i <= m_max; i++ )
    {
        cout << "| " << setw( 4 ) << i << " ";
    }   cout << "|\n";
    
    for( int i = 1; i <= n; i++ )
    {
        cout << "| " << setw( 4 ) << i << " | ";

        for( int j = 1; j <= m_max; j++ )
        {
            // Tutaj pobieramy dane z indexTable zamiast capacityBackpack
            cout << setw( 4 ) << inv[ i - 1 ].indexTable[ j ] << " | ";
        }   cout << "\n";
    }

    cout << dynamicLine << "\n\n";
}

void rozwiazProblemPlecakowy( vector< Przedmiot > &inv, int m_max, int n )
{
    int j = m_max;              // Maks. pojemność plecaka

    for( int i = 0; i < n; i++ )
    {
        for( int danaWaga = 0; danaWaga <= m_max; danaWaga++ )
        {
            if( i == 0 )
            {
                if( inv[ i ].masa <= danaWaga )
                {
                    inv[ i ].capacityBackpack[ danaWaga ] = ( inv[ i ].masa <= danaWaga ) ? inv[ i ].cena : 0;
                    inv[ i ].indexTable[ danaWaga ] = i + 1;                     // Zapamiętujemy numer rzeczy
                }
            }
            else
            {
                if( inv[ i ].masa > danaWaga )
                {
                    inv[ i ].capacityBackpack[ danaWaga ] = inv[ i - 1 ].capacityBackpack[ danaWaga ];
                    inv[ i ].indexTable[ danaWaga ] = inv[ i - 1 ].indexTable[ danaWaga ];
                }
                else
                {
                    int bezPrzedmiotu = inv[ i - 1 ].capacityBackpack[ danaWaga ];
                    int zPrzedmiotem = inv[ i - 1 ].capacityBackpack[ danaWaga - inv[ i ].masa ] + inv[ i ].cena;
    
                    if( bezPrzedmiotu > zPrzedmiotem )
                    {
                        inv[ i ].capacityBackpack[ danaWaga ] = bezPrzedmiotu;
                        inv[ i ].indexTable[ danaWaga ] = inv[ i - 1 ].indexTable[ danaWaga ];
                    }
                    else
                    {
                        inv[ i ].capacityBackpack[ danaWaga ] = zPrzedmiotem;
                        inv[ i ].indexTable[ danaWaga ] = i + 1; // Zapamiętujemy nową rzecz jako ostatnią
                    }
                }
            }
        }
    }
}