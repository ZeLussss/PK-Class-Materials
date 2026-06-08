// Autor: Ksawery Zelek

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Program_01_Przedmiot.h"
using namespace std;

int main()
{
    try
    {
        ios::sync_with_stdio( false );
        cin.tie( NULL );
        cout.tie( NULL );
        
        int m_max;          // Określa maksymalna nosnosc plecaka
        int n;              // Liczba przedmiotow (ile wierszy)
        
        cin >> m_max;
        cin >> n;
    
        cin.ignore();
    
        // Stworzenie tablicy do przechowywania przedmiotow
        vector< Przedmiot > tabPrzedmiotow = { };
    
        for( int i = 0; i < n; i++ )
        {
            // Stworzenie nowego przedmiotu
            Przedmiot nowyPrzedmiot;
    
            // !!!
            // Nowy przedmiot dodawany w formie P_i(m_i, c_i), i=1,2, [...] ,n 
    
            // Pobranie nazwy
            string przedmiotNazwa = "";             
            getline( cin, przedmiotNazwa, '(' );  
            
            // Pobranie masy
            string przedmiotMasa = "";
            getline( cin, przedmiotMasa, ',' );
            int przedmiotMasaInt = stoi( przedmiotMasa );
    
            // Pobranie ceny
            string przedmiotCena = "";
            getline( cin, przedmiotCena, ')' );
            int przedmiotCenaInt = stoi( przedmiotCena );
    
            cin.ignore();
    
            // Dodanie wartosci do nowego przedmiotu
            nowyPrzedmiot.nazwa = przedmiotNazwa;
            nowyPrzedmiot.masa  = przedmiotMasaInt;
            nowyPrzedmiot.cena  = przedmiotCenaInt;
    
            // Nadanie nowemu przedmiotowi pustego wektora z wagą
            nowyPrzedmiot.capacityBackpack.resize( m_max + 1 );
    
            // Nadanie nowemu przedmiotowi pustego wektora, ktory bedzie przechowywal, ktore przedmioty pakujemy
            nowyPrzedmiot.indexTable.resize( m_max + 1 );
    
            // Dodanie nowego przedmiotu do tablicy przedmiotów
            tabPrzedmiotow.push_back( nowyPrzedmiot );
        }
    
        // Wykonanie algorytmu
        rozwiazProblemPlecakowy( tabPrzedmiotow, m_max, n );
        
        printInventory( tabPrzedmiotow );
            
        printWeight_ALL( tabPrzedmiotow, m_max, n );
        printIndex_ALL( tabPrzedmiotow, m_max, n );
    
        // Wyświetlenie zawartości plecaka
        cout << "Przedmioty w plecaku:\n";
        int wagaTymczasowa = m_max;
        while( wagaTymczasowa > 0 )
        {
            int index = tabPrzedmiotow[ n - 1 ].indexTable[ wagaTymczasowa ];
            if( index == 0 ) break;
    
            cout << "- " << tabPrzedmiotow[ index - 1 ].nazwa << "\n";
            wagaTymczasowa -= tabPrzedmiotow[ index - 1 ].masa;
        }
    }
    catch ( const invalid_argument& e ) 
    {
        cerr << "BLAD DANYCH: " << e.what() << "\n";
    }
    catch ( const out_of_range& e ) 
    {
        cerr << "BLAD ZAKRESU: " << e.what() << "\n";
    }
    catch ( const bad_alloc& e ) 
    {
        cerr << "BLAD PAMIECI: Nie udalo sie zarezerwowac miejsca na tabele.\n";
    }
    catch ( const exception& e ) 
    {
        cerr << "WYJATEK: " << e.what() << "\n";
    }
    
    return 0;
}