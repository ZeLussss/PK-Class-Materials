// Autor: Ksawery Zelek

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    cout << "SILNIA: \n";

    unsigned int n = 0;
    
    cout << "Podaj n z ktorej obliczymy n!: ";
    cin >> n;

    unsigned long long silnia = 1;
    bool ok = 1;

    for ( unsigned int i = 2; i <= n; ++i )
    {
        if ( silnia > numeric_limits< unsigned long long >::max() / i )
        {
            cout << "--------------------\n";
            cout << "Przekroczenie zakresu przy mnożeniu przez " << i << "\n";
            cout << n << "! nie mozliwe do obliczenia w typie unsigned long long\n";
            cout << "--------------------\n";
            ok = false;
            break;
        }

        silnia *= i;
    }

    if( ok )
    {
        cout << "Wynik -> " << n << "! = " << silnia << "\n";
    }
    else
    {
        cout << "Wynik wykracza poza zakres\n";
    }

    return 0;
}