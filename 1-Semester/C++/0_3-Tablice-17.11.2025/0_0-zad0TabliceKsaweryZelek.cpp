#include <iostream>
using namespace std;

int sizeOfArr( int* tab, size_t size )
{
    return size;
}

auto average( int* tab, int size )
{
    double sum = 0;

    for( int i = 0; i < size; i++ )
    {
        sum += tab[ i ];
        // cout << i << "|" << tab[ i ] << "\n";
    }

    double avg = sum / size;

    // cout << "Avg: " << avg << " | " << sum << "\n";

    return avg;
}

auto closestToAverage( int* tab, size_t size, double avg )
{
    int nr_indx = 0;
    int closest = tab[ 0 ];
    double minDiff = tab[ 0 ] - avg;
    if( minDiff < 0 ) minDiff = -minDiff;

    for( int i = 0; i < size; i++ )
    {
        double diff = tab[ i ] - avg;
        if( diff < 0 ) diff = -diff;

        if( diff < minDiff )
        {
            minDiff = diff;
            closest = tab[ i ];
            nr_indx = i;
        }
    }

    return nr_indx;
}

int main()
{
    // ------------------------------------
    // Obliczenie długości tablicy

    int tab1[] = { 5, 1, 2, 10, 5, 4 };
    int lenTab1 = sizeOfArr( tab1, ( sizeof( tab1 ) / sizeof( tab1[ 0 ] ) ) );

    cout << "Dlugosc tablicy tab1: " << lenTab1 << "\n";
    // ------------------------------------

    // ------------------------------------
    // Obliczanie średniej
    int tab2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int lenTab2 = sizeof( tab2 ) / sizeof( tab2[ 0 ] );

    auto avgTab2 = average( tab2, lenTab2 );

    cout << "Srednia tablicy tab2: " << lenTab2 << "\n";
    // ------------------------------------

    // ------------------------------------
    // Znajdowanie wartosci najblizej sredniej
    int tab3[] = { -5, 2, 3, 10, 6, 7, -10 };
    int lenTab3 = sizeof( tab3 ) / sizeof( tab3[ 0 ] );
    auto avgTab3 = average( tab3, lenTab3 );

    int closestIndex = closestToAverage( tab3, lenTab3, avgTab3 );

    cout << "Liczba najblizsza sredniej w tablicy tab3 to: " << tab3[ closestIndex ] << " a srednia to: " << avgTab3 << "\n";
    cout << "A Indeks tej liczby to: " << closestIndex << "\n";
    // ------------------------------------
}