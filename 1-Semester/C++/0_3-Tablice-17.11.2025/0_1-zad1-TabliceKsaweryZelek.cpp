#include <iostream>
#include <cmath>
using namespace std;

// Największa wartość w tablicy
int maxValue( int* tab, int n )
{
    int maxVal = tab[ 0 ];
    for( int i = 1; i < n; i++ )
    {
        if( tab[ i ] > maxVal )
        {
            maxVal = tab[ i ];
        }
    }
    return maxVal;
}

// Najmniejsza wartość w tablicy
int minValue( int* tab, int n )
{
    int minVal = tab[ 0 ];
    for( int i = 1; i < n; i++ )
    {
        if( tab[ i ] < minVal )
        {
            minVal = tab[ i ];
        }
    }
    return minVal;
}

// Indeks największej wartości
int indexOfMax( int* tab, int n )
{
    int idx = 0;
    for( int i = 1; i < n; i++ )
    {
        if( tab[ i ] > tab[ idx ] )
        {
            idx = i;
        }
    }
    return idx;
}

// Indeks najmniejszej wartości
int indexOfMin( int* tab, int n )
{
    int idx = 0;
    for( int i = 1; i < n; i++ )
    {
        if( tab[ i ] < tab[ idx ] )
        {
            idx = i;
        }
    }
    return idx;
}

// Największa wartość bezwzględna
int maxAbsValue( int* tab, int n )
{
    int maxAbs = abs( tab[ 0 ] );
    for( int i = 1; i < n; i++ )
    {
        if( abs( tab[ i ] ) > maxAbs )
        {
            maxAbs = abs( tab[ i ] );
        }
    }
    return maxAbs;
}

// Indeks największej wartości bezwzględnej
int indexOfMaxAbs( int* tab, int n )
{
    int idx = 0;
    for( int i = 1; i < n; i++ )
    {
        if( abs( tab[ i ] ) > abs( tab[ idx ] ) )
        {
            idx = i;
        }
    }
    return idx;
}

// Średnia
double average( int* tab, int n )
{
    if( n == 0 ) return 0;

    double sum = 0;
    for( int i = 0; i < n; i++ )
    {
        sum += tab[ i ];
    }
    return sum / n;
}

int main()
{
    int tab[] = { -5, 2, 3, 10, 6, 7, -10 };
    int n = sizeof( tab ) / sizeof( tab[ 0 ] );

    cout << "Tablica: ";
    for( int i = 0; i < n; i++ ) cout << tab[ i ] << " ";
    cout << "\n";

    cout << "Najwieksza wartosc: " << maxValue( tab, n ) << "\n";
    cout << "Najmniejsza wartosc: " << minValue( tab, n ) << "\n";
    cout << "Indeks najwiekszej wartosci: " << indexOfMax( tab, n ) << "\n";
    cout << "Indeks najmniejszej wartosci: " << indexOfMin( tab, n ) << "\n";
    cout << "Najwieksza wartosc bezwzgledna: " << maxAbsValue( tab, n ) << "\n";
    cout << "Indeks najwiekszej wartosci bezwzglednej: " << indexOfMaxAbs( tab, n ) << "\n";

    return 0;
}