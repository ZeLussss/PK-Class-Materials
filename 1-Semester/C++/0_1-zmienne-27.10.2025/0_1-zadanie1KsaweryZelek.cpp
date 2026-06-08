// Autor: Ksawery Zelek

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 0;

    cout << "Podaj wartosc n = ";
    cin >> n;

    cout << "\nTrojki Pitagorejskie z liczb mniejszych od " << n << ":\n";

    int i = 1;
    for( int a = 1; a <= n; a++ )
    {
        for( int b = a; b <= n; b++ )
        {
            for( int c = b; c < n; c++ )
            {
                if( ( a * a ) + ( b * b ) == ( c * c ) )
                {
                    cout << i++ << " | a = " << a << ", b = " << b << ", c = " << c << "\n";
                }
            }
        }
    }
}