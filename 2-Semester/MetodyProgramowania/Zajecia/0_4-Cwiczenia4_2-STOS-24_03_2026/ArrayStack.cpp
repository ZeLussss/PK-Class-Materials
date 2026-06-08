#include <iostream>
#include "ArrayStack.h"

using namespace std;

// Konstruktor alokujacy pamiec
ArrayStack::ArrayStack( int cap )
{
    capacity = cap;
    array = new int[ capacity ];
    topIndex = -1;
}

ArrayStack::~ArrayStack()
{
    delete[] array;
}

bool ArrayStack::isEmpty()
{
    return topIndex == -1;
}

int ArrayStack::getSize()
{
    return topIndex + 1;
}

// Podejrzenie elementu na szczycie
int ArrayStack::peek()
{
    if( isEmpty() )
    {
        cout << "Blad: Stos (tablica) jest pusty!\n";
        return -1;
    }
    return array[ topIndex ];
}

// Dodanie elementu na stos
void ArrayStack::push( int value )
{
    if( topIndex >= capacity - 1 )
    {
        cout << "Blad: Przepełnienie stosu!\n";
        return;
    }
    array[ ++topIndex ] = value;
}

// Usuniecie elementu ze szczytu
void ArrayStack::pop()
{
    if( isEmpty() )
    {
        cout << "Blad: Nie mozna zdjac elementu, stos jest pusty!\n";
        return;
    }
    topIndex--;
}