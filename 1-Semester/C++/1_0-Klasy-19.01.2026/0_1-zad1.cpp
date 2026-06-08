// Autor: Ksawery Zelek
#include <iostream>
#include <string>
using namespace std;

class Zwierze {
protected:
    string imie;
    string rasa;        // 1 zmiana - przenosimy tutaj zmienna 'rasa'
public:
    Zwierze() : imie( "brak" ) { }
    Zwierze( const string & i, const string & r = "nieznana" ) : imie( i ), rasa( r ) { }
    
    virtual void info() const {
        cout << "Mam na imie " << this->imie << endl;
        cout << "Moja rasa: " << this->rasa << "\n";
    }

    void wyswietl_rase() const {
        cout << "Moja rasa: " << rasa << endl;
    }
};

class Pies : public Zwierze {
public:
    Pies() : Zwierze() { }
    
    Pies( const string & i, const string & r ) : Zwierze( i, r ) { }
    
    void info() const override {
        // cout << "Mam na imie " << imie << endl;          // NIEPOTRZEBNE, MOŻNA SKORZYSTAĆ Z METODY RODZICA
        Zwierze::info();
    }
    /*      ^
        Operacja override zabezpiecza przed błędem braku słowa const w klasie pochodnej, ponieważ wymusza pełną 
        zgodność sygnatury z klasą bazową i w razie pomyłki (jak w pierwotnym kodzie) zablokuje kompilację programu.
    */
};

int main()
{
    Pies pies( "Burek", "Mieszaniec" );
    pies.info();
    pies.wyswietl_rase();
    
    cout << "--------------------------\n";
    
    Zwierze zwierz1 = pies;
    zwierz1.info();
    // zwierz1.wyswietl_rase();     
    // Dlaczego to zakomentowałem? 
    /*
        W pierwotnym kodzie klasa Zwierze nie posiadała metody wyswietl_rase(). Obiekt zwierz1 jest typu Zwierze, 
        więc nie widział metod z klasy Pies. (Nawet po moim przeniesieniu rasy do Zwierze, w oryginale był to błąd)
    */
    
    cout << "--------------------------\n";
    
    Zwierze * zwierz2 = &pies;
    zwierz2->info();
    // zwierz2->wyswietl_rase();
    // Dlaczego to zakomentowałem? 
    /*
        Wskaźnik zwierz2 jest typu Zwierze*. Kompilator sprawdza metody
        dostępne w klasie, na którą wskazuje typ wskaźnika (Zwierze), a nie typ obiektu (Pies).
        Metoda ta nie istniała w interfejsie Zwierze.
    */
    
    cout << "--------------------------\n";  
    
    zwierz2 = &zwierz1;
    zwierz2->info();
        
    return 0;
}