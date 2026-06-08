// Autor: Ksawery Zelek
#include <iostream>
using namespace std;

int smaller( const int *a, const int * b )
{
    if( *a < *b )
    {
        return *a;
    }
    else
    {
        return *b;
    }
}

int main()
{
    int a = 10;
    int b = 48;

    int wynik = smaller( &a, &b );

    cout << "Wynik: " << wynik << "\n";
}