// Autor: Ksawery Zelek

#include <iostream>
#include <string>
using namespace std;

void zadanie1()
{
    int x = 50;
    int y = 67;

    cout << "Przed przypisaniem: x = " << x << " y = " << y << "\n";

    cout << "Po przypisaniu: x = " << ( x = y ) << "\n\n";
}

void zadanie2()
{
    int a = 10;
    int b = 5;

    // -----------------------------------------------------
    // 1 Sposób
    cout << "1 sposob: (Ze zmienna pomocnicza)\n";
    cout << "PRZED: \n";
    cout << "a = " << a << "\nb = " << b << "\n";

    int temp = a;
    a = b;
    b = temp;

    cout << "PO: \n";
    cout << "a = " << a << "\nb = " << b << "\n\n";

    // -----------------------------------------------------
    // 2 Sposób
    a = 10;
    b = 5;

    cout << "2 Sposob: (Dodawanie i odejmowanie)\n";
    cout << "PRZED: \n";
    cout << "a = " << a << "\nb = " << b << "\n";

    a = a + b - ( b = a );

    cout << "PO: \n";
    cout << "a = " << a << "\nb = " << b << "\n\n";

    // -----------------------------------------------------
    // 3 Sposób
    a = 10;
    b = 5;

    cout << "3 Sposob: \n";
    cout << "PRZED: \n";
    cout << "a = " << a << "\nb = " << b << "\n";

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "PO: \n";
    cout << "a = " << a << "\nb = " << b << "\n\n";
}

void zadanie3()
{
    int z = 66;

    cout << "Wartosc z (1 krok): " << z++ << "\n";
    cout << "Wartosc z (2 krok): " << z << "\n\n";
}

int main()
{
    string line( 15, '-' );

    cout << line << "\nZadanie1 \n" << line << "\n";
    zadanie1();

    cout << line << "\nZadanie2 \n" << line << "\n";
    zadanie2();

    cout << line << "\nZadanie3 \n" << line << "\n";
    zadanie3();
}