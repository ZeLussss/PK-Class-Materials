#include <iostream>

using namespace std;

// Funkcja tworząca tablicę
int* create_array( int n )
{
    int* tablica = new int[ n ];

    for( int i = 0; i < n; i++ )
    {
        cin >> tablica[ i ];
    }

    return tablica;
}

// Algorytm liczący największą sumę
long long kadane_algorithm( const int* numbers, int length, int &start, int &end )
{
    long long max_sum = 0; 
    long long curr_sum = 0;

    int s = 0;

    start = -1;
    end = -1;

    for( int i = 0; i < length; i++ )
    {
        long long temp_val;

        // Obliczanie wartości dla liczb dodatnich i ujemnych
        if( numbers[ i ] > 0 )
        {
            temp_val = 3LL * numbers[ i ];
        }
        else
        {
            temp_val = 2LL * numbers[ i ];
        }

        curr_sum += temp_val;

        // Zerowanie sumy, jeśli jest ujemna
        if( curr_sum < 0 )
        {
            curr_sum = 0;
            s = i + 1;
        }
        // Aktualizacja maksymalnej sumy i indeksów
        else if( curr_sum > max_sum )
        {
            max_sum = curr_sum;
            start = s;
            end = i;
        }
    }

    return max_sum;
}

// Funkcja przetwarzająca pojedynczy zestaw danych
void process_test_case()
{
    int n;

    // Wczytanie rozmiaru tablicy
    if( !( cin >> n ) )
    {
        return;
    }

    int* tablica = create_array( n );

    int start = -1;
    int koniec = -1;

    // Wywołanie algorytmu
    long long wynik = kadane_algorithm( tablica, n, start, koniec );

    cout << start << " " << koniec << " " << wynik << "\n";

    delete[] tablica;
}

// Funkcja main
int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );

    int z;

    // Wczytanie liczby zestawów danych
    if( !( cin >> z ) )
    {
        return 0;
    }

    while( z-- )
    {
        process_test_case();
    }

    return 0;
}