// Autor: Ksawery Zelek
// Temat: Funkcja zwracająca sumę cyfr liczby będącej argumentem wywołania

#include <iostream>
#include <string>
using namespace std;

int functionReturningSum( unsigned int num )
{
    unsigned int temp = num;
    unsigned int suma = 0;

    while( temp > 0 )
    {
        suma += temp % 10;
        temp /= 10;
    }

    cout << "Suma cyfr liczby <" << num << "> to: " << suma << "\n";

    return suma;
}

int main()
{
    int x = functionReturningSum( 1234 );
    int y = functionReturningSum( 123473 );
    int z = functionReturningSum( 2 );
    int w = functionReturningSum( 4619 );

    cout << "Wartosc zwrocona z funkcji( 4619 ) = " << w << "\n";
}