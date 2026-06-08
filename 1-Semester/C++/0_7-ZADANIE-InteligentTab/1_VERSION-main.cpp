#include <iostream>
#include <string>
#include "InteligentIntTab.hpp"
using namespace std;

// --------------------------------------------

string line( 32, '-' );

// --------------------------------------------

int main()
{
// _______________________________________________________________________________

    cout << line << "\n\n";
    cout << "TEST 1\n";

    InteligentIntTab tab1( 100 );   // Powinien zarezerwowac 100 miejsc, ale nic wiecej
    tab1.printAll();

    // A teraz uzupelnijmy ja zerami
    tab1.fillWithZeros();
    tab1.printAll();

    cout << '\n';

// _______________________________________________________________________________

    cout << line << "\n\n";           // Lista inicjalizacyjna
    cout << "TEST 2\n";

    InteligentIntTab tab2{ 4, 5, 6, 1, 2, 7, 0, 1, 2, 3, 5 };
    tab2.printAll();

    cout << '\n';

// _______________________________________________________________________________

    cout << line << "\n\n";
    cout << "TEST 3\n";

    InteligentIntTab tab3 = { 4, 5, 6 };        // Kopia tablicy (Deep copy, ponieważ mamy wskaźniki) (Sprawdzenie czy funkcja operator= działa)
    InteligentIntTab tab4;

    cout << "PRZED:\n";
    cout << "Tab3: \n";
    tab3.printAll();
    cout << "Tab4: \n";
    tab4.printAll();
    
    tab4 = tab3;

    cout << "PO:\n";
    cout << "Tab3: \n";
    tab3.printAll();
    cout << "Tab4: \n";
    tab4.printAll();

    cout << '\n';

// _______________________________________________________________________________

    cout << line << "\n\n";
    cout << "TEST 4\n";

    // Kopiowanie danych przed konstruktor oraz dodanie wartosci przez .push_back()
    // Wykorzystamy obecna tab3, oraz nowa tablice tab5

    InteligentIntTab tab5( tab3 );

    cout << "SPRAWDZENIE:\n";
    cout << "Tab3: \n";
    tab3.printAll();
    cout << "Tab5: \n";
    tab5.printAll();
    cout << '\n';

    // Oraz dodanie wartosci do tab3 oraz tab5
    tab3.push_back( 30 );
    tab5.push_back( 50 );
    cout << '\n';

    // Sprawdzenie
    cout << "Tab3: \n";
    tab3.printAll();
    cout << "Tab5: \n";
    tab5.printAll();
    cout << '\n';

// _______________________________________________________________________________ 

    cout << line << "\n\n";
    cout << "TEST5 \n";         // Sprawdzenie czy funkcja operator[] działa

    InteligentIntTab tab6 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    cout << "PRZED:\n";
    tab6.printAll();
    cout << '\n';

    // Zmiana wartosci tablicy oraz wydrukowanie
    for( int i = 0; i < 10; i++ )
    {
        tab6[ i ] *= 10;
    }

    cout << "PO:\n";
    for( int i = 0; i < 10; i++ )
    {
        cout << i << ": " << tab6[ i ] << '\n';
    }

    cout << "\n" << line << "\n";

// _______________________________________________________________________________ 
}

// --------------------------------------------