// Autor: Ksawery Zelek

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Program_02_Funkcje.h"
using namespace std;

int main()
{
    ios::sync_with_stdio( false );
    cin.tie( NULL );
    cout.tie( NULL );

    try
    {
        int z;          // Liczba zestawow danych
        cin >> z;
    
        for( int i = 0; i < z; i++ )
        {
            int cel;        // Pojemnosc plecaka
            int k;          // Liczba elementow, mogacych wypelniac plecak
            cin >> cel;
            cin >> k;
    
            vector< int > arr;      // Tablica niepowtarzajacych sie liczb calkowitych, ktore sa wagami kolejnych elemntow
            
            for( int j = 0; j < k; j++ )
            {
                int temp;
                cin >> temp;
    
                arr.push_back( temp );
            }
    
            cout << rozwiazProblem( arr, cel ) << "\n";
        }
    }
    catch (const exception& e) 
    {
        cerr << "WYJATEK: " << e.what() << endl;
        return 1;
    }
}