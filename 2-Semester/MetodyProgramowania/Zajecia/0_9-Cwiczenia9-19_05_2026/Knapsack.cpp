#include <iostream>
#include <iomanip>
#include "Knapsack.h"

using namespace std;

/* ------------------------------------------------------------ */

bool read_Data_From_File( string file_name,
                          vector< Przedmiot > &items,
                          int &n,
                          int &W )
{
    ifstream file( file_name );

    if( !file.is_open() )
        return false;

    if( !( file >> n >> W ) )
        return false;

    if( n <= 0 || W <= 0 )
        return false;

    items.clear();

    for( int i = 0; i < n; i++ )
    {
        Przedmiot temp;

        if( !( file >> temp.p >> temp.w >> temp.p_w ) )
            return false;

        if( temp.p <= 0 || temp.w <= 0 || temp.p_w <= 0 )
            return false;

        items.push_back( temp );
    }

    file.close();

    return true;
}

/* ------------------------------------------------------------ */

void print_Vector( ofstream &file,
                   vector< int > &x,
                   int level )
{
    file << "(";

    for( int i = 0; i < ( int )x.size(); i++ )
    {
        if( i <= level )
            file << x[ i ];
        else
            file << "-";

        if( i + 1 < ( int )x.size() )
            file << ", ";
    }

    file << ")";
}

/* ------------------------------------------------------------ */

double calculate_Bound_For_Knapsack( int level,
                                     int profit,
                                     int weight,
                                     vector< Przedmiot > &items,
                                     int W )
{
    if( weight > W )
        return 0.0;

    int n = items.size();

    double bound = profit;
    int lonweight = weight;
    int j = level + 1;

    while( j < n && lonweight + items[ j ].w <= W )
    {
        lonweight += items[ j ].w;
        bound += items[ j ].p;
        j++;
    }

    if( j < n )
    {
        bound += ( W - lonweight ) * items[ j ].p_w;
    }

    return bound;
}

/* ------------------------------------------------------------ */

bool is_Promising( double bound,
                   int best )
{
    return bound > best;
}

/* ------------------------------------------------------------ */

void check_Node( int level,
                 int profit,
                 int weight,
                 vector< int > &x,
                 int &best,
                 vector< int > &best_x,
                 vector< Przedmiot > &items,
                 int W,
                 ofstream &file )
{
    double bound = calculate_Bound_For_Knapsack( level,
                                                 profit,
                                                 weight,
                                                 items,
                                                 W );

    file << "Wezel: ";
    print_Vector( file, x, level );
    file << endl;

    file << "level = " << level << endl;
    file << "profit = " << profit << endl;
    file << "weight = " << weight << endl;
    file << fixed << setprecision( 2 );
    file << "bound = " << bound << endl;

    if( weight <= W && profit > best )
    {
        best = profit;
        best_x = x;

        file << "Nowe najlepsze rozwiazanie." << endl;
        file << "best = " << best << endl;
    }

    if( weight > W )
    {
        file << "Przekroczono pojemnosc plecaka." << endl;
        file << "Wezel nie jest obiecujacy." << endl;
        file << "Powrot." << endl;
        file << "------------------------------------------------------------" << endl;
        return;
    }

    if( level == ( int )items.size() - 1 )
    {
        file << "Osiagnieto lisc drzewa." << endl;
        file << "Powrot." << endl;
        file << "------------------------------------------------------------" << endl;
        return;
    }

    if( is_Promising( bound, best ) )
    {
        file << "Wezel jest obiecujacy." << endl;
        file << "Schodzimy do kolejnych dzieci wezla." << endl;
        file << "------------------------------------------------------------" << endl;

        int next = level + 1;

        x[ next ] = 1;

        check_Node( next,
                    profit + items[ next ].p,
                    weight + items[ next ].w,
                    x,
                    best,
                    best_x,
                    items,
                    W,
                    file );

        x[ next ] = 0;

        check_Node( next,
                    profit,
                    weight,
                    x,
                    best,
                    best_x,
                    items,
                    W,
                    file );
    }
    else
    {
        file << "Wezel nie jest obiecujacy." << endl;
        file << "bound <= best" << endl;
        file << "Odciecie galezi." << endl;
        file << "Powrot." << endl;
        file << "------------------------------------------------------------" << endl;
    }
}
