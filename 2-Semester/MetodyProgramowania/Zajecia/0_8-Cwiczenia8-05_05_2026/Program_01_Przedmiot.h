// Autor: Ksawery Zelek

#pragma once
#include <string>
#include <vector>
using namespace std;

/**
 * @struct Przedmiot
 * @brief Reprezentuje pojedyńczy przedmiot oraz historię optymalizacji plecaka
 */
struct Przedmiot
{
    string nazwa;
    int masa;
    int cena;

    /**
     * @brief Tabela P_ij. Przechowuje koszty przedmiotów.
     */
    vector< int > capacityBackpack;        

    /**
     * @brief Tabela Q_ij. Przechowuje indeksy przedmiotów.
     */
    vector< int > indexTable;               
};

/**
 * @brief Wypisuje listę wszystkich wczytanych przedmiotów w formie tabeli.
 * @param inv Stała referencja do wektora przedmiotów do wyświetlenia.
 */
void printInventory( const vector< Przedmiot > &inv );

/**
 * @brief Wyświetla macierz P dla wszystkich przedmiotów i wag.
 * @param inv Wektor przedmiotów z wypełnionymi wektorami capacityBackpack.
 * @param m_max Maksymalna nośność plecaka.
 * @param n Liczba przedmiotów.
 */
void printWeight_ALL( const vector< Przedmiot > &inv, int m_max, int n );

/**
 * @brief Wyświetla macierz Q ułatwiającą odtworzenie wyniku.
 * @param inv Wektor przedmiotów z wypełnionymi wektorami indexTable.
 * @param m_max Maksymalna nośność plecaka.
 * @param n Liczba przedmiotów.
 */
void printIndex_ALL( const vector< Przedmiot > &inv, int m_max, int n );

/**
 * @brief Implementacja algorytmu programowania dynamicznego dla problemu plecakowego.
 * 
 * Funkcja wypełnia pola capacityBackpack oraz indexTable dla każdego przedmiotu,
 * bazując na wynikach uzyskanych dla poprzedniego elementu w wektorze.
 * 
 * @param inv Referencja do wektora przedmiotów, który zostanie zmodyfikowany.
 * @param m_max Maksymalna dopuszczalna waga plecaka.
 * @param n Liczba dostępnych przedmiotów.
 */
void rozwiazProblemPlecakowy( vector< Przedmiot > &inv, int m_max, int n );