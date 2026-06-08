// Autor: Ksawery Zelek
#include <iostream>
using namespace std;

int sumPointers( const int *a, const int *b )
{
    return *a + *b;
}

int main()
{
    int x = 10;
    int y = 20;

    cout << "Suma: " << sumPointers( &x, &y ) << "\n";
}
