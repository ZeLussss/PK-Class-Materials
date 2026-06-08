// Autor: Ksawery Zelek

#include "Functions.h"
#include <iostream>

using namespace std;

/* ==================================================================== */
/* FUNKCJE POMOCNICZE                                                   */
/* ==================================================================== */

void printVectorTab_2D( const vector< vector <int> >& arr )
{
    cout << "___ Array 2D \n";
    for( const auto& rows : arr )
    {
        cout << "| ";
        for( const auto& cols : rows )
        {
            cout << cols << " ";
        }
        cout << " |\n";
    }
}

/* ==================================================================== */
/* FUNKCJE REKURENCYJNE                                                 */
/* ==================================================================== */

int binSearchFirstRec( const vector <int>& row, int target, int L, int R )
{
    if( L > R ) return -1;
    int mid = L + ( R - L ) / 2;
    
    if( row[ mid ] == target )
    {
        int left_res = binSearchFirstRec( row, target, L, mid - 1 );
        return ( left_res != -1 ) ? left_res : mid;
    }
    else if( row[ mid ] > target )
    {
        return binSearchFirstRec( row, target, L, mid - 1 );
    }
    else
    {
        return binSearchFirstRec( row, target, mid + 1, R );
    }
}

int binSearchLastRec( const vector <int>& row, int target, int L, int R )
{
    if( L > R ) return -1;
    int mid = L + ( R - L ) / 2;
    
    if( row[ mid ] == target )
    {
        int right_res = binSearchLastRec( row, target, mid + 1, R );
        return ( right_res != -1 ) ? right_res : mid;
    }
    else if( row[ mid ] > target )
    {
        return binSearchLastRec( row, target, L, mid - 1 );
    }
    else
    {
        return binSearchLastRec( row, target, mid + 1, R );
    }
}

void f_rekPier( const vector< vector <int> >& arr, int target, int row )
{
    if( row >= arr.size() )
    {
        cout << "RekPier: nie ma " << target << "\n";
        return;
    }
    
    int col = binSearchFirstRec( arr[ row ], target, 0, arr[ row ].size() - 1 );
    
    if( col != -1 )
    {
        cout << "RekPier: " << target << " w (" << row << "," << col << ")\n";
        return;
    }
    
    f_rekPier( arr, target, row + 1 );
}

void f_rekOst( const vector< vector <int> >& arr, int target, int row )
{
    if( row < 0 )
    {
        cout << "RekOst: nie ma " << target << "\n";
        return;
    }
    
    int col = binSearchLastRec( arr[ row ], target, 0, arr[ row ].size() - 1 );
    
    if( col != -1 )
    {
        cout << "RekOst: " << target << " w (" << row << "," << col << ")\n";
        return;
    }
    
    f_rekOst( arr, target, row - 1 );
}

/* ==================================================================== */
/* FUNKCJE ITERACYJNE                                                   */
/* ==================================================================== */

void f_iterPier( const vector< vector <int> >& arr, int target )
{
    int n = arr.size();
    if( n == 0 ) return;
    int m = arr[ 0 ].size();
    
    for( int i = 0; i < n; ++i )
    {
        int L = 0;
        int R = m - 1;
        int found_col = -1;
        
        while( L <= R )
        {
            int mid = L + ( R - L ) / 2;
            if( arr[ i ][ mid ] == target )
            {
                found_col = mid;
                R = mid - 1; 
            }
            else if( arr[ i ][ mid ] > target )
            {
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        
        if( found_col != -1 )
        {
            cout << "IterPier: " << target << " w (" << i << "," << found_col << ")\n";
            return;
        }
    }
    cout << "IterPier: nie ma " << target << "\n";
}

void f_iterOst( const vector< vector <int> >& arr, int target )
{
    int n = arr.size();
    if( n == 0 ) return;
    int m = arr[ 0 ].size();
    
    for( int i = n - 1; i >= 0; --i )
    {
        int L = 0;
        int R = m - 1;
        int found_col = -1;
        
        while( L <= R )
        {
            int mid = L + ( R - L ) / 2;
            if( arr[ i ][ mid ] == target )
            {
                found_col = mid;
                L = mid + 1; 
            }
            else if( arr[ i ][ mid ] > target )
            {
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        
        if( found_col != -1 )
        {
            cout << "IterOst: " << target << " w (" << i << "," << found_col << ")\n";
            return;
        }
    }
    cout << "IterOst: nie ma " << target << "\n";
}