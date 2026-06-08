#pragma once 
#include <iostream>
#include <initializer_list>

using namespace std;

// ---------------------------------------

template <typename T>
class InteligentTab
{
private:
    T* numberStore = nullptr; 
    int currentSize = 0;      
    int elementsCount = 0;

    void allocateMoreMemory();

public:
    ~InteligentTab()
    {
        delete[] numberStore;
    }

    InteligentTab( int size = 1 );

    InteligentTab( const InteligentTab<T>& other ); 

    InteligentTab( initializer_list< T > list ); 

    T& operator[]( int index ); 

    InteligentTab<T>& operator=( const InteligentTab<T>& other );

    void push_back( T x ); 

    int getSize();

    T getElement( int index ) const; 

    void printAll();

    void fillWithZeros();

    void clear();
};

// --------------------------------------------
// DEFINICJE FUNKCJI
// --------------------------------------------

template <typename T>
InteligentTab<T>::InteligentTab( int size )
{
    // new T[...]
    T* tab = new T[ size ]; 
    currentSize = size;
    elementsCount = 0;

    delete[] numberStore; 

    numberStore = tab;
}

// --------------------------------------------

template <typename T>
InteligentTab<T>::InteligentTab( const InteligentTab<T>& other )
{
    currentSize = other.currentSize;
    elementsCount = other.elementsCount;

    numberStore = new T[ currentSize ];

    for( int i = 0; i < elementsCount; i++ )
    {
        numberStore[ i ] = other.numberStore[ i ];
    }

    cout << "Skopiowano tablice! Utworzono wlasna pamiec." << '\n';
}

// --------------------------------------------

template <typename T>
InteligentTab<T>::InteligentTab( initializer_list< T > list )
{
    currentSize = list.size();
    elementsCount = list.size();

    numberStore = new T[ currentSize ];

    int i = 0;
    for( T x : list ) // T x
    {
        numberStore[ i ] = x;
        i++;
    }

    cout << "Utworzono tablice z listy inicjalizacyjnej!" << '\n';
}

// --------------------------------------------

template <typename T>
int InteligentTab<T>::getSize()
{
    return elementsCount;
}

// --------------------------------------------

template <typename T>
T InteligentTab<T>::getElement( int index ) const
{
    if( index < 0 || index >= elementsCount ) return T(); 

    return numberStore[ index ];
}

// --------------------------------------------

template <typename T>
T& InteligentTab<T>::operator[]( int index )
{
    if( index < 0 || index >= elementsCount )
    {
        cout << "BLAD: Wartosc index poza zakresem!\n";
    }

    return numberStore[ index ];
}

// --------------------------------------------

template <typename T>
InteligentTab<T>& InteligentTab<T>::operator=( const InteligentTab<T>& other )
{
    if( this == &other )
    {
        return *this;
    }

    delete[] numberStore;

    currentSize = other.currentSize;
    elementsCount = other.elementsCount;

    numberStore = new T[ currentSize ];

    for( int i = 0; i < elementsCount; i++ )
    {
        numberStore[ i ] = other.numberStore[ i ];
    }

    cout << "!!! OPERATOR PRZYPISANIA DZIALA !!!\n";

    return *this;
}

// --------------------------------------------

template <typename T>
void InteligentTab<T>::allocateMoreMemory()
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
    
    T* newTab = new T[ currentSize ];

    for( int i = 0; i < elementsCount; i++ ) 
    {
        newTab[ i ] = numberStore[ i ];
    }

    delete[] numberStore;

    numberStore = newTab;

    cout << "Powiekszono do: " << currentSize << '\n';
}

// --------------------------------------------

template <typename T>
void InteligentTab<T>::push_back( T x ) 
{
    if( elementsCount == currentSize )
    {
        allocateMoreMemory();
    }

    numberStore[ elementsCount ] = x;

    elementsCount++;
}

// --------------------------------------------

template <typename T>
void InteligentTab<T>::printAll()
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

template <typename T>
void InteligentTab<T>::fillWithZeros()
{
    elementsCount = currentSize;

    for( int i = 0; i < elementsCount; i++ )
    {
        numberStore[ i ] = T();  
    }
}

// --------------------------------------------

template <typename T>
void InteligentTab<T>::clear()
{
    elementsCount = 0;
}

// --------------------------------------------