#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    string line = string( 15, '-' );

    struct TDane
    {
        string imie;
        string nazwisko;
        string miejsceZamieszkania;
        int dzienUrodzenia;
        int miesiacUrodzenia;
        int rokUrodzenia;
    };
    
    TDane osoba1;
    osoba1.imie = "Ksawery";
    osoba1.nazwisko = "Zelek";
    osoba1.miejsceZamieszkania = "Krakow";
    osoba1.dzienUrodzenia = 16;
    osoba1.miesiacUrodzenia = 9;
    osoba1.rokUrodzenia = 2005;

    cout << line << "\n";
    cout << osoba1.imie << " " << osoba1.nazwisko << "\n";
    cout << line << "\n\n";

    cout << line << "\n";
    cout << "Imie: " << osoba1.imie << "\n";
    cout << "Nazwisko: " << osoba1.nazwisko << "\n";
    cout << "Miejsce zamieszkania: " << osoba1.miejsceZamieszkania << "\n";
    cout << "Data urodzenia: " << osoba1.dzienUrodzenia << "." << osoba1.miesiacUrodzenia << "." << osoba1.rokUrodzenia << "\n";
    cout << line << "\n\n";

    cout << line << "\n";
    cout << "Przyk\tladowy n\na\tpi\0s" << "\n";
    cout << line << "\n\n";

    // Aktorzy
    vector< pair< string, string > > aktorzy = {
        make_pair( "Robert", "Downey Jr." ),
        make_pair( "Johnny", "Depp" ),
        make_pair( "Daniel", "Radcliffe" ),
        make_pair( "Keanu", "Reeves" )
    };

    cout << line << "\n";
    cout << "POPULARNI AKTORZY: \n";

    int x = 1;
    for( pair< string, string > aktor : aktorzy )
    {
        cout << x++ << ":\t" << aktor.first << "\t" << aktor.second << "\n";
    }
    
    cout << line << "\n";
}