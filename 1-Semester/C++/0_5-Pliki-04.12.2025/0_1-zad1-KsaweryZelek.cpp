// Autor: Ksawery Zelek

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void przepisz_plik( const string& plik_zrodlowy, const string& plik_docelowy ) 
{
    ifstream in( plik_zrodlowy, ios::binary );     
    ofstream out( plik_docelowy, ios::binary );  

    if ( !in || !out ) 
    {
        cerr << "Błąd otwarcia pliku!\n";
        return;
    }

    ofstream clear( plik_docelowy, ios::trunc );
    out << in.rdbuf();  // kopiowanie zawartości

    in.close();
    out.close();
}

int main() 
{
    przepisz_plik( "wejscie.txt", "wyjscie.txt" );
    return 0;
}