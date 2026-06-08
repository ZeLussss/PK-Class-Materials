#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;

// --------------------------------------------

class InteligentIntTab
{
private:
    int* numberStore = nullptr;
    int currentSize = 0;
    int elementsCount = 0;

    void allocateMoreMemory();

public:
    ~InteligentIntTab()
    {
        delete[] numberStore;
    }

    InteligentIntTab() = default;

    InteligentIntTab( int size );

    InteligentIntTab( const InteligentIntTab& other );

    InteligentIntTab( initializer_list< int > list );

    int& operator[]( int index );

    InteligentIntTab& operator=( const InteligentIntTab& other );

    void push_back( int x );

    int getSize();

    int getElement( int index ) const;

    void printAll();

    void fillWithZeros();

    void clear();
};

// --------------------------------------------

InteligentIntTab::InteligentIntTab( int size )
{
    int* tab = new int[ size ];
    currentSize = size;
    elementsCount = 0;

    delete[] numberStore;

    numberStore = tab;
}

// --------------------------------------------

InteligentIntTab::InteligentIntTab( const InteligentIntTab& other )
{
    currentSize = other.currentSize;
    elementsCount = other.elementsCount;

    numberStore = new int[ currentSize ];

    for( int i = 0; i < elementsCount; i++ )
    {
        numberStore[ i ] = other.numberStore[ i ];
    }

    cout << "Skopiowano tablice! Utworzono wlasna pamiec." << '\n';
}

// --------------------------------------------

InteligentIntTab::InteligentIntTab( initializer_list< int > list )
{
    currentSize = list.size();
    elementsCount = list.size();

    numberStore = new int[ currentSize ];

    int i = 0;
    for( int x : list )
    {
        numberStore[ i ] = x;
        i++;
    }

    cout << "Utworzono tablice z listy inicjalizacyjnej!" << '\n';
}

// --------------------------------------------

int InteligentIntTab::getSize()
{
    return elementsCount;
}

// --------------------------------------------

int InteligentIntTab::getElement( int index ) const
{
    if( index < 0 || index >= elementsCount ) return -1;

    return numberStore[ index ];
}

// --------------------------------------------

int& InteligentIntTab::operator[]( int index )
{
    if( index < 0 || index >= elementsCount )
    {
        cout << "BLAD: Wartosc index poza zakresem!\n";
    }

    return numberStore[ index ];
}

// --------------------------------------------

InteligentIntTab& InteligentIntTab::operator=( const InteligentIntTab& other )
{
    if( this == &other )
    {
        return *this;
    }

    delete[] numberStore;

    currentSize = other.currentSize;
    elementsCount = other.elementsCount;

    numberStore = new int[ currentSize ];

    for( int i = 0; i < elementsCount; i++ )
    {
        numberStore[ i ] = other.numberStore[ i ];
    }

    cout << "!!! OPERATOR PRZYPISANIA DZIALA !!!\n";

    return *this;       // Pozwala na takie operacje a = b = c
}

// --------------------------------------------

void InteligentIntTab::allocateMoreMemory()
{
    cout << "Wczesniejszy rozmiar: " << currentSize << '\n';

    if( currentSize == 0 )
    {
        currentSize = 1;
    }
    else
    {
        currentSize *= 2;
    }
    
    int* newTab = new int[ currentSize ];

    for( int i = 0; i < elementsCount; i++ ) 
    {
        newTab[ i ] = numberStore[ i ];
    }

    delete[] numberStore;

    numberStore = newTab;

    cout << "Powiekszono do: " << currentSize << '\n';
}

// --------------------------------------------

void InteligentIntTab::push_back( int x )
{
    if( elementsCount == currentSize )
    {
        allocateMoreMemory();
    }

    numberStore[ elementsCount ] = x;

    elementsCount++;
}

// --------------------------------------------

void InteligentIntTab::printAll()
{
    cout << "[ ";

    for( int i = 0; i < elementsCount; i++ )
    {
        cout << numberStore[ i ] << " ";
    }
    cout << "]\n";

    cout << "(Rozmiar: " << elementsCount << ", Pojemnosc: " << currentSize << ")\n";
}

// --------------------------------------------

void InteligentIntTab::fillWithZeros()
{
    elementsCount = currentSize;

    for( int i = 0; i < elementsCount; i++ )
    {
        numberStore[ i ] = 0;
    }
}

// --------------------------------------------

void InteligentIntTab::clear()
{
    elementsCount = 0;
}

// --------------------------------------------