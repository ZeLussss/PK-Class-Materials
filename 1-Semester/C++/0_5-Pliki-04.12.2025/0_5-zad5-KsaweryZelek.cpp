// Autor: Ksawery Zelek

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool wczytaj_do_pliku( vector< vector< int > >& tab2D, size_t sizeX, size_t sizeY, const string& sciezka )
{
    ifstream in( sciezka, ios::binary );

    if( !in )
    {
        cerr << "Nie mozna otworzyc pliku " << sciezka << "\n";
        return false;
    }

    tab2D.assign( sizeX, vector< int >( sizeY ) );

    
    for ( size_t i = 0; i < sizeX; ++i ) 
    {
        in.read( reinterpret_cast< char* >( tab2D[ i ].data() ), static_cast< std::streamsize >( sizeY * sizeof( int ) ) );
        if( !in ) 
        {
            cerr << "Blad odczytu wiersza " << i << "\n";
            return false;
        }
    }
    return true;
}

int main()
{
    vector< vector< int > > tab;

    if( wczytaj_do_pliku( tab, 4, 4, "vector.txt" ) )
    {
        for( const auto& row : tab )
        {
            for( auto x : row )
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}