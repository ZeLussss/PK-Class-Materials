// Autor: Ksawery Zelek

#include <iostream>
#include <initializer_list>
using namespace std;

class Time{
	int hour;      // 0-23
	int minute;    // 0-59
	int second;    // 0-59
public:
    Time(int h = 0, int m = 0, int s = 0) : hour( h ), minute( m ), second( s ) { }     // Zmieniony konstruktor

	void print() const{                                             // Dodanie consta na sam koniec znaczy, że obiecujemy zmiennej, że nic nie zmienimy w obiekcie
		cout << hour << ":"<< minute << ":" << second << endl; 
	}
};
int main(){	
	Time t1;
	Time t2(10);
	Time t3(10, 12);
	const Time t4(10, 12, 45);
	t1.print();
	t2.print();
	t3.print();
	t4.print();
	return 0;

    // Rozmiar ->

    // Aktualnie nasz program przechowuje wartości w typie int, który zajmuje 4 bajty to złe rozwiązanie, 
    // Po co nam tyle pamięci, jeżeli przechowujemy tylko wartości od 0-23, 0-59, oraz 0-59.
    // Bardziej do tego zadania nada się unsigned char, albo signed char ( w obu zachowuje się zakres od 0-59)
    // a do tego zajmują tylko po 1B pamięci.
    // Więc zamiast 12B pamięci (4+4+4 przy int), możemy zmiejszyć zużywaną pamięć do 3B(1+1+1 przy char)
}