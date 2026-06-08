#include "algorytmy.h"

using namespace std;

/**
 * @brief Zlicza wystąpienia wartości przy użyciu wyszukiwania binarnego O(log n).
 * Oblicza różnicę między skrajnym lewym a prawym indeksem szukanego elementu.
 */
long long zliczElementy( long long* tab, int size, long long value )
{
    int left = 0, right = size - 1;
    int first = -1, last = -1;

    while( left <= right )
    {
        int mid = left + ( right - left ) / 2;
        if( tab[ mid ] == value )
        {
            first = mid;
            right = mid - 1;
        }
        else if( tab[ mid ] < value ) left = mid + 1;
        else right = mid - 1;
    }

    if( first == -1 ) return 0; 

    left = 0; 
    right = size - 1;
    
    while( left <= right )
    {
        int mid = left + ( right - left ) / 2;
        if( tab[ mid ] == value )
        {
            last = mid;
            left = mid + 1;
        }
        else if( tab[ mid ] < value ) left = mid + 1;
        else right = mid - 1;
    }

    return last - first + 1;
}

/**
 * @brief Wyszukiwanie interpolacyjne. Przewiduje pozycję szukanego elementu 
 * na podstawie wartości na krańcach aktualnego przedziału.
 */
int wyszukiwanieInterpolacyjne( long long* tab, int size, long long value )
{
    int left = 0, right = size - 1;

    if( tab[ left ] == value && tab[ right ] == value ) return 0;

    while( left <= right && value >= tab[ left ] && value <= tab[ right ] )
    {
        if( left == right )
        {
            if( tab[ left ] == value ) return left;
            return -1;
        }

        long long pos = left + ( ( double )( right - left ) / ( tab[ right ] - tab[ left ] ) ) * ( value - tab[ left ] );

        if( tab[ pos ] == value ) return pos;
        if( tab[ pos ] < value ) left = pos + 1;
        else right = pos - 1;
    }
    
    return -1;
}

void wypiszBezDuplikatow( ofstream& outFile, long long* tab, int size )
{
    if( size == 0 ) return;

    long long* uniqueValues = new long long[ size ];
    uniqueValues[ 0 ] = tab[ 0 ];
    int uniqueCount = 1;

    for( int i = 1; i < size; i++ )
    {
        if( tab[ i ] != tab[ i - 1 ] )
        {
            uniqueValues[ uniqueCount ] = tab[ i ];
            uniqueCount++;
        }
    }

    int toPrint = uniqueCount > 200 ? 200 : uniqueCount;
    
    for( int i = 0; i < toPrint; i++ )
    {
        outFile << uniqueValues[ i ] << " ";
        if( ( i + 1 ) % 50 == 0 ) outFile << "\n";
    }
    if( toPrint % 50 != 0 ) outFile << "\n";

    delete[] uniqueValues;
}

void przetworzZestaw( ifstream& inFile, ofstream& outFile, long long* tab, int size )
{
    int q;
    inFile >> q;

    long long* queries = new long long[ q ];
    
    for( int i = 0; i < q; i++ )
    {
        inFile >> queries[ i ];
    }

    for( int i = 0; i < q; i++ )
    {
        long long count = zliczElementy( tab, size, queries[ i ] );
        int index = wyszukiwanieInterpolacyjne( tab, size, queries[ i ] );
        outFile << "(" << count << " " << index << ") ";
    }
    outFile << "\n";

    wypiszBezDuplikatow( outFile, tab, size );

    delete[] queries;
}