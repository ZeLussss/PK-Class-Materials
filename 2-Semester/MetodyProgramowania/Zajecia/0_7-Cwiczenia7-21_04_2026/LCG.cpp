#include "LCG.h"

vector< int >uniquePrimeFactors( int m )
{
    vector< int >factors;

    int d = 2;

    while( m > 1 )
    {
        if( m % d == 0 )
        {
            factors.push_back( d );

            while( m % d == 0 )
            {
                m = m / d;
            }
        }

        d++;
    }

    return factors;
}

int find_A_For_LCG( int m )
{
    vector< int > requirements = uniquePrimeFactors( m );

    if( m % 4 == 0 )
    {
        requirements.push_back( 4 );
    }

    int bestA = -1;

    for( int a = 0; a < m; a++ )
    {
        if( a < 2 )
        {
            continue;
        }

        bool isCorrect_A = true;

        for( int i = 0; i < requirements.size(); i++ )
        {
            if( ( a - 1 ) % requirements[ i ] != 0 )
            {
                isCorrect_A = false;
                break;
            }
        }

        if( isCorrect_A )
        {
            bestA = a;
        }
    }

    return bestA;
}

vector< int >generate_numbers_by_LCG( int n, int m, int X_0, int a, int c )
{
    vector< int > generated_Numbers = { };

    generated_Numbers.push_back( X_0 );

    for( int i = 1; i < n; i++ )
    {
        int temp_X_n;

        temp_X_n = ( a * generated_Numbers[ i - 1 ] + c ) % m;

        generated_Numbers.push_back( temp_X_n );
    }

    return generated_Numbers;
}

vector< int >LCG_Algorithm()
{
    // ----------------------------------------------
    // [1]
    // Pobieramy X_max oraz n
    // ----------------------------------------------
    int X_max, n;

    X_max = checkIfPositive( checkCinStream( "X_max" ), "X_max" );
    n = checkIfPositive( checkCinStream( "n" ), "n" );

    int m = X_max + 1;

    // ----------------------------------------------
    // [2]
    // Pobieramy X_0
    // ----------------------------------------------
    int X_0;

    while( true )
    {
        int temp_X_0;

        temp_X_0 = checkCinStream( string( "X_0 (Zakres od 0 do " + to_string( X_max ) + " )" ) );

        if( temp_X_0 < 0 || temp_X_0 >= m )
        {
            cout << "[!] BLAD ZAKRESU: X_0 musi byc z zakresu od 0 do " << X_max << "!\n";
        }
        else
        {
            X_0 = temp_X_0;
            break;
        }
    }

    // ----------------------------------------------
    // [3]
    // Szukamy c
    // ----------------------------------------------
    vector< int > correct_c;

    for( int c = 1; c < m; c++ )
    {
        if( NWD( c, m ) == 1 )
        {
            correct_c.push_back( c );
        }
    }

    if( correct_c.empty() )
    {
        cout << "[!] BLAD: Nie znaleziono poprawnego c dla m = " << m << "!\n";
        return {};
    }

    int index, c;
    int numberOfCorrect_C = correct_c.size();

    index = X_0 % numberOfCorrect_C;
    c = correct_c[ index ];

    // ----------------------------------------------
    // [4]
    // Szukamy a
    // ----------------------------------------------
    int a = find_A_For_LCG( m );

    if( a == -1 )
    {
        cout << "[!] BLAD: Nie znaleziono poprawnego a dla m = " << m << "!\n";
        return {};
    }

    // ----------------------------------------------
    // [5]
    // Generujemy liczby
    // ----------------------------------------------
    return generate_numbers_by_LCG( n, m, X_0, a, c );
}