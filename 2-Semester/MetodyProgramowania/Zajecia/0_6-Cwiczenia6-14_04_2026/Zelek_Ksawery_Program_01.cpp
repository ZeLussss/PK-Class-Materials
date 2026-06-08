// Autor: Ksawery Zelek

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Functions.h"
using namespace std;

/* ==================================================================== */
/* FUNKCJA GŁÓWNA                                                       */
/* ==================================================================== */

int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );

    try
    {
        int n;
        if( !( cin >> n ) ) return 0;
        
        if( n <= 0 )
        {
            throw invalid_argument( "Liczba zestawow danych musi byc dodatnia." );
        }

        for( int i = 0; i < n; i++ )
        {
            int rows, cols;
            cin >> rows >> cols;
            
            if( rows <= 0 || cols <= 0 )
            {
                throw invalid_argument( "Wymiary tablicy musza byc dodatnie." );
            }

            vector< vector <int> > tab( rows, vector <int> ( cols ) );

            for( int j = 0; j < rows; j++ )
            {
                for( int k = 0; k < cols; k++ )
                {
                    cin >> tab[ j ][ k ];
                }
            }

            int numToFind;
            cin >> numToFind;

            f_rekPier( tab, numToFind, 0 );
            f_rekOst( tab, numToFind, tab.size() - 1 );
            f_iterPier( tab, numToFind );
            f_iterOst( tab, numToFind );

            cout << "---\n";
        }
    } 
    catch( const invalid_argument& e )
    {
        cerr << "Blad danych wejsciowych: " << e.what() << "\n";
    }
    catch( const bad_alloc& e )
    {
        cerr << "Blad alokacji pamieci: " << e.what() << "\n";
    }
    catch( const exception& e )
    {
        cerr << "Wystapil nieoczekiwany wyjatek: " << e.what() << "\n";
    }

    return 0;
}