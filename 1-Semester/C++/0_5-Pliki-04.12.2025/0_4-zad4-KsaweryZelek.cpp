// Autor: Ksawery Zelek

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool zapisz_do_pliku( const vector< vector< int > >& tab2D, size_t sizeX, size_t sizeY, const string& sciezka )
{
    // Określanie sizeX oraz sizeY nie jest potrzebne przy daniu jako arg. vectora, ale wpisałem, ponieważ było tak w treści zadania
    ofstream out( sciezka, ios::binary | ios::app );

    if( !out )
    {
        cerr << "Nie mozna otworzyc pliku " << sciezka << "\n";
        return false;
    }
    
    ofstream clear( sciezka, ios::trunc ); 

    if( !out ) 
    {
        cerr << "Nie mozna otworzyc pliku " << sciezka << "\n";
        return false;
    }

    
    for( const auto& row : tab2D )
    {
        out.write( reinterpret_cast< const char* >( row.data() ), static_cast< std::streamsize >( row.size() * sizeof( int ) ) );
        if( !out )
        {
            cerr << "Blad zapisu wiersza\n";
            return false;
        }
    }
    return true;
}

int main()
{
    vector< vector< int > > tab = { { 4, 5, 6, 7 }, 
                                    { 8, 9, 10, 11 },
                                    { 12, 13, 14, 15 }, 
                                    { 16, 17, 18, 19 } };

    zapisz_do_pliku( tab, tab.size(), tab[ 0 ].size(), "vector.txt" );
}