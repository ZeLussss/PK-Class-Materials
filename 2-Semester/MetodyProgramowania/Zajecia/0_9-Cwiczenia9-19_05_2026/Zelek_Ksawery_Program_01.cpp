#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Knapsack.h"

using namespace std;

/* ------------------------------------------------------------ */

int main()
{
    string input_file;
    string output_file;

    vector< Przedmiot > items;

    int n;
    int W;

    cout << "Podaj nazwe pliku wejsciowego: ";
    cin >> input_file;

    if( !read_Data_From_File( input_file, items, n, W ) )
    {
        cout << "Blad wczytywania danych z pliku." << endl;
        return 1;
    }

    cout << "Podaj nazwe pliku wyjsciowego: ";
    cin >> output_file;

    ofstream file( output_file );

    if( !file.is_open() )
    {
        cout << "Blad otwarcia pliku wyjsciowego." << endl;
        return 1;
    }

    vector< int > x( n, 0 );
    vector< int > best_x( n, 0 );

    int best = 0;

    file << "START\n";
    file << "------------------------------------------------------------\n";

    check_Node( -1,
                0,
                0,
                x,
                best,
                best_x,
                items,
                W,
                file );

    file << "WYNIK KONCOWY\n";
    file << "------------------------------------------------------------\n";
    
file << "Najwiekszy zysk: " << best << endl;

int total_weight = 0;

file << "x = (";

for( int i = 0; i < n; i++ )
{
    file << best_x[i];

    if( best_x[i] == 1 )
        total_weight += items[i].w;

    if( i < n - 1 )
        file << ", ";
    }

    file << ")" << endl;

    /* -------- wybrane przedmioty -------- */
    file << "Wybrane przedmioty: ";

    for( int i = 0; i < n; i++ )
    {
        if( best_x[i] == 1 )
            file << i + 1 << " ";
    }

    file << endl;

    file << "Waga = " << total_weight << endl;

    file.close();

    cout << "OK - zapisano wynik.\n";

    return 0;
}