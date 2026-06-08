// Autor: Ksawery Zelek

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void dopisz_do_pliku( const string& plik_zrodlowy, const string& plik_docelowy ) 
{
    ifstream in( plik_zrodlowy, ios::binary );     
    ofstream out( plik_docelowy, ios::binary | ios::app );    

    if ( !in || !out ) 
    {
        cerr << "Błąd otwarcia pliku!\n";
        return;
    }

    out << in.rdbuf();  // kopiowanie zawartości

    in.close();
    out.close();
}

int main() 
{
    dopisz_do_pliku( "wejscie.txt", "wyjscie.txt" );
    return 0;
}