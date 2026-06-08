// Autor: Ksawery Zelek

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void dopisz_do_pliku( const int* tab, size_t rozmiar, const string& sciezka )
{
    ofstream out( sciezka, ios::binary | ios::app );

    if( !out )
    {
        cerr << "Nie mozna otworzyc pliku " << sciezka << "\n";
        return;
    }

    for( size_t i = 0; i < rozmiar; i++ )
    {
        out << tab[ i ] << '\n';
    }
}

int main()
{
    int dane[] = { 10, 20, 30, 40 };
    dopisz_do_pliku( dane, 4, "wynik.txt" );
    return 0;
}