#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Struktura przechowujaca dane pojedynczego przedmiotu.
 */
struct Przedmiot
{
    int p;
    int w;
    double p_w;
};

/**
 * @brief Wczytuje dane problemu plecakowego z pliku tekstowego.
 *
 * Plik wejsciowy powinien miec postac:
 *
 * n W
 * p1 w1 p1/w1
 * p2 w2 p2/w2
 * ...
 * pn wn pn/wn
 *
 * @param file_name nazwa pliku wejsciowego
 * @param items wektor przedmiotow
 * @param n liczba przedmiotow
 * @param W pojemnosc plecaka
 *
 * @return true jezeli dane zostaly poprawnie wczytane
 * @return false jezeli wystapil blad wczytywania
 */
bool read_Data_From_File( string file_name,
                          vector< Przedmiot > &items,
                          int &n,
                          int &W );

/**
 * @brief Wypisuje aktualny wektor rozwiazania do pliku.
 *
 * @param file strumien pliku wyjsciowego
 * @param x aktualny wektor rozwiazania
 * @param level aktualny poziom drzewa
 */
void print_Vector( ofstream &file,
                   vector< int > &x,
                   int level );

/**
 * @brief Oblicza gorne ograniczenie zysku dla aktualnego wezla.
 *
 * Funkcja wykorzystuje wzor:
 *
 * lonweight = weight + suma wag przedmiotow mieszczacych sie w calosci
 *
 * bound = profit + suma p[j] + ( W - lonweight ) * p[k] / w[k]
 *
 * gdzie k oznacza pierwszy przedmiot, ktory powoduje przekroczenie
 * dopuszczalnej pojemnosci plecaka.
 *
 * @param level aktualny poziom drzewa
 * @param profit aktualny zysk
 * @param weight aktualna waga
 * @param items wektor przedmiotow
 * @param W pojemnosc plecaka
 *
 * @return wartosc gornego ograniczenia
 */
double calculate_Bound_For_Knapsack( int level,
                                     int profit,
                                     int weight,
                                     vector< Przedmiot > &items,
                                     int W );

/**
 * @brief Sprawdza, czy aktualny wezel jest obiecujacy.
 *
 * Wezel jest obiecujacy, gdy jego gorne ograniczenie jest wieksze
 * od aktualnie najlepszego znalezionego zysku.
 *
 * @param bound gorne ograniczenie zysku
 * @param best aktualnie najlepszy zysk
 *
 * @return true jezeli wezel jest obiecujacy
 * @return false jezeli wezel nie jest obiecujacy
 */
bool is_Promising( double bound,
                   int best );

/**
 * @brief Realizuje algorytm z powrotami dla problemu plecakowego 0-1.
 *
 * Funkcja przechodzi po drzewie decyzji. Dla kazdego przedmiotu
 * rozpatruje dwie mozliwosci: wziecie przedmiotu albo jego odrzucenie.
 *
 * @param level aktualny poziom drzewa
 * @param profit aktualny zysk
 * @param weight aktualna waga
 * @param x aktualny wektor rozwiazania
 * @param best najlepszy znaleziony zysk
 * @param best_x najlepszy znaleziony wektor rozwiazania
 * @param items wektor przedmiotow
 * @param W pojemnosc plecaka
 * @param file strumien pliku wyjsciowego
 */
void check_Node( int level,
                 int profit,
                 int weight,
                 vector< int > &x,
                 int &best,
                 vector< int > &best_x,
                 vector< Przedmiot > &items,
                 int W,
                 ofstream &file );

#endif