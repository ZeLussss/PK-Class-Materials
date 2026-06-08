#include "AdditiveCongruence.h"

vector< pair< int, int > >createRecomendedPairListOfNumbers()
{
    vector< pair< int, int > >arr;

    arr.push_back( make_pair( 1, 2 ) );
    arr.push_back( make_pair( 1, 3 ) );
    arr.push_back( make_pair( 1, 4 ) );
    arr.push_back( make_pair( 2, 5 ) );
    arr.push_back( make_pair( 1, 6 ) );
    arr.push_back( make_pair( 1, 7 ) );
    arr.push_back( make_pair( 3, 7 ) );
    arr.push_back( make_pair( 4, 9 ) );
    arr.push_back( make_pair( 3, 10 ) );
    arr.push_back( make_pair( 2, 11 ) );

    arr.push_back( make_pair( 1, 15 ) );
    arr.push_back( make_pair( 4, 15 ) );
    arr.push_back( make_pair( 7, 15 ) );
    arr.push_back( make_pair( 3, 17 ) );
    arr.push_back( make_pair( 5, 17 ) );
    arr.push_back( make_pair( 6, 17 ) );
    arr.push_back( make_pair( 7, 18 ) );
    arr.push_back( make_pair( 3, 20 ) );
    arr.push_back( make_pair( 2, 21 ) );
    arr.push_back( make_pair( 1, 22 ) );

    arr.push_back( make_pair( 5, 23 ) );
    arr.push_back( make_pair( 9, 23 ) );
    arr.push_back( make_pair( 3, 25 ) );
    arr.push_back( make_pair( 7, 25 ) );
    arr.push_back( make_pair( 3, 28 ) );
    arr.push_back( make_pair( 9, 28 ) );
    arr.push_back( make_pair( 13, 28 ) );
    arr.push_back( make_pair( 2, 29 ) );
    arr.push_back( make_pair( 3, 31 ) );
    arr.push_back( make_pair( 6, 31 ) );

    arr.push_back( make_pair( 7, 31 ) );
    arr.push_back( make_pair( 13, 31 ) );
    arr.push_back( make_pair( 13, 33 ) );
    arr.push_back( make_pair( 2, 35 ) );
    arr.push_back( make_pair( 11, 36 ) );
    arr.push_back( make_pair( 4, 39 ) );
    arr.push_back( make_pair( 8, 39 ) );
    arr.push_back( make_pair( 14, 39 ) );
    arr.push_back( make_pair( 3, 41 ) );
    arr.push_back( make_pair( 20, 41 ) );

    arr.push_back( make_pair( 5, 47 ) );
    arr.push_back( make_pair( 14, 47 ) );
    arr.push_back( make_pair( 20, 47 ) );
    arr.push_back( make_pair( 21, 47 ) );
    arr.push_back( make_pair( 9, 49 ) );
    arr.push_back( make_pair( 12, 49 ) );
    arr.push_back( make_pair( 15, 49 ) );
    arr.push_back( make_pair( 22, 49 ) );
    arr.push_back( make_pair( 3, 52 ) );
    arr.push_back( make_pair( 19, 52 ) );

    arr.push_back( make_pair( 21, 52 ) );
    arr.push_back( make_pair( 24, 55 ) );
    arr.push_back( make_pair( 7, 57 ) );
    arr.push_back( make_pair( 22, 57 ) );
    arr.push_back( make_pair( 19, 58 ) );
    arr.push_back( make_pair( 1, 60 ) );
    arr.push_back( make_pair( 11, 60 ) );
    arr.push_back( make_pair( 1, 63 ) );
    arr.push_back( make_pair( 5, 63 ) );
    arr.push_back( make_pair( 31, 63 ) );

    arr.push_back( make_pair( 18, 65 ) );
    arr.push_back( make_pair( 32, 65 ) );
    arr.push_back( make_pair( 9, 68 ) );
    arr.push_back( make_pair( 33, 68 ) );
    arr.push_back( make_pair( 6, 71 ) );
    arr.push_back( make_pair( 9, 71 ) );
    arr.push_back( make_pair( 18, 71 ) );
    arr.push_back( make_pair( 20, 71 ) );
    arr.push_back( make_pair( 35, 71 ) );
    arr.push_back( make_pair( 25, 73 ) );

    arr.push_back( make_pair( 28, 73 ) );
    arr.push_back( make_pair( 31, 73 ) );
    arr.push_back( make_pair( 9, 79 ) );
    arr.push_back( make_pair( 19, 79 ) );
    arr.push_back( make_pair( 4, 81 ) );
    arr.push_back( make_pair( 16, 81 ) );
    arr.push_back( make_pair( 35, 81 ) );
    arr.push_back( make_pair( 13, 84 ) );
    arr.push_back( make_pair( 13, 87 ) );
    arr.push_back( make_pair( 38, 89 ) );

    arr.push_back( make_pair( 2, 93 ) );
    arr.push_back( make_pair( 21, 94 ) );
    arr.push_back( make_pair( 11, 95 ) );
    arr.push_back( make_pair( 17, 95 ) );
    arr.push_back( make_pair( 6, 97 ) );
    arr.push_back( make_pair( 12, 97 ) );
    arr.push_back( make_pair( 33, 97 ) );
    arr.push_back( make_pair( 34, 97 ) );
    arr.push_back( make_pair( 11, 98 ) );
    arr.push_back( make_pair( 27, 98 ) );

    return arr;
}

pair< int, int >choosePairForAdditiveCongruenceMethod( int n )
{
    vector< pair< int, int > >recommendedPairsOfNumbers;
    vector< pair< int, int > >correctPairsFor_N;

    recommendedPairsOfNumbers = createRecomendedPairListOfNumbers();

    for( int i = 0; i < recommendedPairsOfNumbers.size(); i++ )
    {
        int j = recommendedPairsOfNumbers[ i ].first;
        int k = recommendedPairsOfNumbers[ i ].second;

        if( j >= 1 && k <= n && j < k )
        {
            correctPairsFor_N.push_back( recommendedPairsOfNumbers[ i ] );
        }
    }

    if( correctPairsFor_N.empty() )
    {
        cout << "[!] BLAD: Nie znaleziono zadnej poprawnej pary dla n = " << n << "!\n";
        return make_pair( -1, -1 );
    }

    cout << "\nPoprawne pary dla n = " << n << ":\n";

    for( int i = 0; i < correctPairsFor_N.size(); i++ )
    {
        cout << "[" << i + 1 << "] - ";
        cout << "(" << correctPairsFor_N[ i ].first << ", " << correctPairsFor_N[ i ].second << ")\n";
    }

    int choice;

    while( true )
    {
        choice = checkCinStream( "numer pary" );

        if( choice < 1 || choice > correctPairsFor_N.size() )
        {
            cout << "[!] BLAD ZAKRESU: Wybierz numer pary od 1 do " << correctPairsFor_N.size() << "!\n";
        }
        else
        {
            break;
        }
    }

    return correctPairsFor_N[ choice - 1 ];
}

vector< int >createStartTable_X_ForAdditiveCongruenceMethod( int n, int m )
{
    if( m <= 1 )
    {
        cout << "[!] BLAD: m musi byc wieksze od 1, zeby stworzyc tablice X przez LCG!\n";
        return {};
    }

    int X_0;

    while( true )
    {
        int temp_X_0;

        temp_X_0 = checkCinStream( string( "X_0 dla LCG (Zakres od 0 do " + to_string( m - 1 ) + " )" ) );

        if( temp_X_0 < 0 || temp_X_0 >= m )
        {
            cout << "[!] BLAD ZAKRESU: X_0 musi byc z zakresu od 0 do " << m - 1 << "!\n";
        }
        else
        {
            X_0 = temp_X_0;
            break;
        }
    }

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

    int numberOfCorrect_C = correct_c.size();
    int index = X_0 % numberOfCorrect_C;
    int c = correct_c[ index ];

    int a = find_A_For_LCG( m );

    if( a == -1 )
    {
        cout << "[!] BLAD: Nie znaleziono poprawnego a dla m = " << m << "!\n";
        return {};
    }

    vector< int > X;

    X = generate_numbers_by_LCG( n, m, X_0, a, c );

    return X;
}

vector< int >generate_numbers_by_AdditiveCongruenceMethod( int amountOfNumbers, int m, vector< int > Y, pair< int, int > selectedPair )
{
    vector< int > generated_Numbers = { };

    int n = Y.size();

    int j = selectedPair.first - 1;
    int k = selectedPair.second - 1;

    for( int i = 0; i < amountOfNumbers; i++ )
    {
        Y[ k ] = ( Y[ j ] + Y[ k ] ) % m;

        generated_Numbers.push_back( Y[ k ] );

        j--;
        k--;

        if( j < 0 )
        {
            j = n - 1;
        }

        if( k < 0 )
        {
            k = n - 1;
        }
    }

    return generated_Numbers;
}

vector< int >additiveCongruenceMethod()
{
    int n, m, amountOfNumbers;

    n = checkIfPositive( checkCinStream( "n - rozmiar tablicy pamieci" ), "n" );
    m = checkIfPositive( checkCinStream( "m" ), "m" );
    amountOfNumbers = checkIfPositive( checkCinStream( "liczbe elementow do wygenerowania" ), "liczba elementow do wygenerowania" );

    vector< int > X;

    X = createStartTable_X_ForAdditiveCongruenceMethod( n, m );

    if( X.empty() )
    {
        cout << "[!] BLAD: Nie udalo sie utworzyc tablicy X!\n";
        return {};
    }

    cout << "\nTablica X:\n";
    printVector_INT_1D( X );

    vector< int > Y;

    Y = reverseVector_INT_1D( X );

    cout << "\nTablica Y:\n";
    printVector_INT_1D( Y );

    pair< int, int > selectedPair;

    selectedPair = choosePairForAdditiveCongruenceMethod( n );

    if( selectedPair.first == -1 || selectedPair.second == -1 )
    {
        return {};
    }

    cout << "\nWybrana para z tabeli: ";
    cout << "(" << selectedPair.first << ", " << selectedPair.second << ")\n";

    cout << "Para po zamianie na indeksy C++: ";
    cout << "(" << selectedPair.first - 1 << ", " << selectedPair.second - 1 << ")\n";

    vector< int > generated_Numbers;

    generated_Numbers = generate_numbers_by_AdditiveCongruenceMethod( amountOfNumbers, m, Y, selectedPair );

    return generated_Numbers;
}