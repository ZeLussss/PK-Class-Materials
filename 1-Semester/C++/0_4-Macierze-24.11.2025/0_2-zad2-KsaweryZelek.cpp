// Autor: Ksawery Zelek
#include <iostream>
using namespace std;

void swapNumbers( int &num1, int &num2 )
{
    int temp = num1;

    num1 = num2;
    num2 = temp;
}

int main()
{
    int num1 = 5; 
    int num2 = 10;

    cout << "--- PRZED ZAMIANA ---\n";
    cout << "num1: " << num1 << " | num2: " << num2 << "\n\n";

    swapNumbers( num1, num2 );

    cout << "--- PO ZAMIANIE ---\n";
    cout << "num1: " << num1 << " | num2: " << num2 << "\n";
}