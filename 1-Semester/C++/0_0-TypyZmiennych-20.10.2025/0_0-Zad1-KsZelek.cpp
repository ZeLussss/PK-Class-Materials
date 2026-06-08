#include <iostream>
#include <string>
#include <limits>
using namespace std;

void header( string text, string line )
{
    cout << line << "\n";
    cout << text << "\n";
    cout << line << "\n";
}

int main()
{
    string line = string( 15, '-' );

    struct TZmienne
    {
        int valueInt;                               // 1
        unsigned int valueUnsignedInt;              // 2
        long valueLong;                             // 3
        unsigned long valueUnsignedLong;            // 4
        long long valueLongLong;                    // 5
        unsigned long long valueUnsignedLongLong;   // 6
        float valueFloat;                           // 7
        char valueChar;                             // 8
        short valueShort;                           // 9
        char32_t valueChar32_t;                     // 10
    };
    TZmienne zmienne;

    cout << "rozmiar obiektu TZmienne: " << sizeof( zmienne ) << "\n\n";


    // -----------------
    // ROZMIARY TYPOW DANYCH
    // -----------------
    header( "Jaki rozmiar?", line );
    cout << "Rozmiar typu int to " << sizeof( zmienne.valueInt ) << " bajtow\n";
    cout << "Rozmiar typu unsigned int to " << sizeof( zmienne.valueUnsignedInt ) << " bajtow\n";
    cout << "Rozmiar typu long to " << sizeof( zmienne.valueLong ) << " bajtow\n";
    cout << "Rozmiar typu unsigned long to " << sizeof( zmienne.valueUnsignedLong ) << " bajtow\n";
    cout << "Rozmiar typu long long to " << sizeof( zmienne.valueLongLong ) << " bajtow\n";
    cout << "Rozmiar typu unsigned long long to " << sizeof( zmienne.valueUnsignedLongLong ) << " bajtow\n";
    cout << "Rozmiar typu float to " << sizeof( zmienne.valueFloat ) << " bajtow\n";
    cout << "Rozmiar typu char to " << sizeof( zmienne.valueChar ) << " bajtow\n";
    cout << "Rozmiar typu short to " << sizeof( zmienne.valueShort ) << " bajtow\n";
    cout << "Rozmiar typu char32_t to " << sizeof( zmienne.valueChar32_t ) << " bajtow\n\n";

    // -----------------
    // GRANICE TYPOW DANYCH
    // -----------------
    header( "Jakie sa granice?", line );
    
    cout << "INT\n" 
    << "Min: " << numeric_limits< int >::min() << "\n"
    << "Max: " << numeric_limits< int >::max() << "\n\n";

    cout << "UNSIGNED INT\n" 
    << "Min: " << numeric_limits< unsigned int >::min() << "\n"
    << "Max: " << numeric_limits< unsigned int >::max() << "\n\n";

    cout << "LONG\n" 
    << "Min: " << numeric_limits< long >::min() << "\n"
    << "Max: " << numeric_limits< long >::max() << "\n\n";

    cout << "UNSIGNED LONG\n" 
    << "Min: " << numeric_limits< unsigned long >::min() << "\n"
    << "Max: " << numeric_limits< unsigned long >::max() << "\n\n";
    
    cout << "LONG LONG\n"
    << "Min: " << numeric_limits< long long >::min() << "\n"
    << "Max: " << numeric_limits< long long >::max() << "\n\n";

    cout << "UNSIGNED LONG LONG\n"
    << "Min: " << numeric_limits< unsigned long long >::min() << "\n"
    << "Max: " << numeric_limits< unsigned long long >::max() << "\n\n";

    cout << "FLOAT\n"
    << "Min: " << numeric_limits< float >::min() << "\n"
    << "Max: " << numeric_limits< float >::max() << "\n\n";

    cout << "CHAR\n"
    << "Min: " << int( numeric_limits< char >::min() ) << "\n"
    << "Max: " << int( numeric_limits< char >::max() ) << "\n\n";

    cout << "SHORT\n"
    << "Min: " << numeric_limits< short >::min() << "\n"
    << "Max: " << numeric_limits< short >::max() << "\n\n";

    cout << "CHAR32_T\n"
    << "Min: " << numeric_limits< char32_t >::min() << "\n"
    << "Max: " << numeric_limits< char32_t >::max() << "\n\n";

    // -----------------
    // CO JAK PRZEKROCZYMY WARTOSC MAX?
    // -----------------
    zmienne.valueInt = int( numeric_limits< int >::max() );
    cout << "Wartosc valueInt przed inkrementacja: " << zmienne.valueInt << "\n";
    zmienne.valueInt++;
    cout << "Wartosc valueInt po inkrementacji: " << zmienne.valueInt << "\n\n";

    zmienne.valueUnsignedLongLong = static_cast< unsigned long long >( numeric_limits< unsigned long long >::max() );
    cout << "Wartosc valueUnsignedLongLong przed inkremetacjaL " << zmienne.valueUnsignedLongLong << "\n";
    zmienne.valueUnsignedLongLong++;
    cout << "Wartosc valueUnsignedLongLong po inkremtacji: " << zmienne.valueUnsignedLongLong << "\n\n";

    zmienne.valueShort = short( numeric_limits< short >::max() );
    cout << "Wartosc valueShort przed inkrementacja: " << zmienne.valueShort << "\n";
    zmienne.valueShort++;
    cout << "Wartosc valueShort po inkrementacji: " << zmienne.valueShort << "\n";

    return 0;
}