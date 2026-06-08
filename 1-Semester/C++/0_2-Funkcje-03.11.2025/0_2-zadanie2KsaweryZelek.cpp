// Autor: Ksawery Zelek
// Temat: Silnia - rekurencyjnie i iteracyjnie.

#include <iostream>
#include <limits>
using namespace std;

unsigned long long silniaRekurencyjnie( unsigned long long n )
{
    if( n <= 1 )
    {
        return 1;
    }
    else
    {
        return n * silniaRekurencyjnie( n - 1 );
    }
}

unsigned long long silniaIteracyjnie( unsigned long long n )
{
    unsigned long long sum = 1;

    for( unsigned long long i = n; i > 1; i-- )
    {
        sum *= i;
    }

    return sum;
}

unsigned long long silnia( unsigned long long n, bool sposobWykonania = 0 )
{
    if( !sposobWykonania )
    {
        return silniaIteracyjnie( n );
    }
    else
    {
        return silniaRekurencyjnie( n );
    }
}

int main()
{
    auto x1 = silniaRekurencyjnie( 5 );
    cout << "silniaRekurencyjnie( 5 ) = " << x1 << "\n";

    auto x2 = silniaIteracyjnie( 5 );
    cout << "silniaIteracyjnie( 5 ) = " << x2 << "\n";

    auto x3 = silnia( 10, 0 );
    cout << "silnia( 10, 0 ) = " << x3 << "\n";

    auto x4 = silnia( 10, 1 );
    cout << "silnia( 10, 1 ) = " << x4 << "\n";

    auto x5 = silnia( 6 );
    cout << "silnia( 6 ) = " << x5 << "\n"; 

    auto x6 = silniaRekurencyjnie( 20 );
    cout << "silniaRekurencyjnie( 20 ) = " << x6 << "\n";

    auto x7 = silniaIteracyjnie( 20 );
    cout << "silniaIteracyjnie( 20 ) = " << x7 << "\n";
}