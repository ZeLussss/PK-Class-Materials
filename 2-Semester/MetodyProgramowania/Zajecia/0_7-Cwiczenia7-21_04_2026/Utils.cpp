#include "Utils.h"

void printVector_INT_1D( vector< int > arr )
{
    cout << "[";

    for( int i = 0; i < arr.size(); i++ )
    {
        cout << arr[ i ];

        if( i != arr.size() - 1 )
        {
            cout << ", ";
        }
    }

    cout << "]\n";
}

vector< int >reverseVector_INT_1D( vector< int > arr )
{
    vector< int > reversedArr = { };

    for( int i = arr.size(); i > 0; i-- )
    {
        reversedArr.push_back( arr[ i - 1 ] );
    }

    return reversedArr;
}

int checkCinStream( const string &nameOfVariable )
{
    int temp;

    while( true )
    {
        cout << "Podaj " << nameOfVariable << ": ";

        if( cin >> temp )
        {
            return temp;
        }

        cout << "[!] BLAD: To nie liczba!\n";

        cin.clear();
        cin.ignore( numeric_limits< streamsize >::max(), '\n' );
    }
}

int checkIfPositive( const int &number, const string &nameOfVariable )
{
    int temp_number = number;

    while( temp_number <= 0 )
    {
        cout << "[!] BLAD: " << nameOfVariable << " musi byc dodatnia!\n";

        temp_number = checkCinStream( nameOfVariable );
    }

    return temp_number;
}

int NWD( int a, int b )
{
    while( b != 0 )
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int NWW( int a, int b )
{
    return( a / NWD( a, b ) ) * b;
}