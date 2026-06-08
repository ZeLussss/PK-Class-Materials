// Autor: Ksawery Zelek
#include <iostream>
#include <iomanip>
using namespace std;

void swapArrays( int *tab1, int lenX1, int lenY1,
                 int *tab2, int lenX2, int lenY2 )
{
    
    if ( lenX1 != lenX2 || lenY1 != lenY2 )
    {
        cerr << "Error: różne wymiary tablic!" << "\n";
        return;
    }

    
    int **tabTemp = new int*[ lenY1 ];
    for( int y = 0; y < lenY1; y++ )
    {
        tabTemp[ y ] = new int[ lenX1 ];
    }


    // Zachowanie poprzedniej tablicy tab1
    for( int y = 0; y < lenY1; y++ )
    {
        for( int x = 0; x < lenX1; x++ )
        {
            tabTemp[ y ][ x ] = tab1[ y * lenX1 + x ];
        }
    }

    // Przeniesienie tab2 do tab1
    for( int y = 0; y < lenY2; y++ )
    {
        for( int x = 0; x < lenX2; x++ )
        {
            tab1[ y * lenX1 + x ] = tab2[ y * lenX2 + x ];
        }
    }

    // Przeniesienie tab1 do tab2 za pomocą zmiennej pomocniczej
    for( int y = 0; y < lenY1; y++ )
    {
        for( int x = 0; x < lenX1; x++ )
        {
            tab2[ y * lenX1 + x ] = tabTemp[ y ][ x ];
        }
    }

    
    for( int y = 0; y < lenY1; y++ ) 
    {
        delete[] tabTemp[ y ];
    }
    delete[] tabTemp;
}

void printTab( int *tab, int lenX, int lenY )
{
    for( int y = 0; y < lenY; y++ )
    {
        for( int x = 0; x < lenX; x++ )
        {
            cout << setw( 4 ) << tab[ y * lenX + x ] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int tab1[ 3 ][ 3 ] = { { 1, 2, 3 },
                           { 4, 5, 6 },
                           { 7, 8, 9 } };

    int tab2[ 3 ][ 3 ] = { { 11, 12, 13 },
                           { 14, 15, 16 },
                           { 17, 18, 19 } };

    // Przed zamianą
    cout << "--- TABLICE PRZED ZAMIANA ---" << "\n";

    cout << "tab1: \n";
    printTab( tab1[ 0 ], 3, 3 );

    cout << "\ntab2: \n";
    printTab( tab2[ 0 ], 3, 3 );

    cout << "\n\n";

    // Zamiana
    swapArrays( &tab1[ 0 ][ 0 ], 3, 3, &tab2[ 0 ][ 0 ], 3, 3 );

    // Po zamianie
    cout << "--- TABLICE PO ZMIANIE ---" << "\n";

    cout << "tab1: \n";
    printTab( tab1[ 0 ], 3, 3 );

    cout << "\ntab2: \n";
    printTab( tab2[ 0 ], 3, 3 );

    cout << "\n\n";
}