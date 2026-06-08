#include <iostream>
#include <vector>

#include "Utils.h"
#include "LCG.h"
#include "AdditiveCongruence.h"

using namespace std;

int main()
{
    cout << "GENERATOR LICZB LOSOWYCH\n\n";

    int choice = -1;

    do
    {
        cout << "---\nWybierz typ generatora:\n";
        cout << "[1] - LCG (Liniowy generator kongruencyjny)\n";
        cout << "[2] - Addytywna metoda kongruencyjna\n";

        cout << "\nTwoj wybor: ";

        choice = checkCinStream( "choice" );

        if( choice == 1 )
        {
            cout << "\n--- METODA LCG ---\n";

            vector< int >generated_numbers;

            generated_numbers = LCG_Algorithm();

            if( !generated_numbers.empty() )
            {
                printVector_INT_1D( generated_numbers );
            }
            else
            {
                cout << "Funkcja nic nie zwrocila!\n";
            }
        }
        else if( choice == 2 )
        {
            cout << "\n--- Addytywna metoda kongruencyjna ---\n";

            vector< int >generated_numbers;

            generated_numbers = additiveCongruenceMethod();

            if( !generated_numbers.empty() )
            {
                cout << "\nWygenerowane liczby:\n";
                printVector_INT_1D( generated_numbers );
            }
            else
            {
                cout << "Funkcja nic nie zwrocila!\n";
            }
        }
        else
        {
            cout << "PODAJ LICZBE Z ZAKRESU <1,2>!\n\n---\n";
        }

    } while( choice != 1 && choice != 2 );

    return 0;
}