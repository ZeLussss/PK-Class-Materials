// Autor: Ksawery Zelek
#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

// ==================================================================================================================
/**
 * @brief Wlasna klasa wyjatkow dla programu kodowania Huffmana.
 */
class HuffmanException : public runtime_error
{
public:
    /**
     * @brief Konstruktor wyjatku Huffmana.
     * @param message Tresc komunikatu bledu.
     */
    HuffmanException( const string& message );
};

// ==================================================================================================================
/**
 * @brief Komparator uzywany w kolejce priorytetowej podczas budowania drzewa Huffmana.
 */
struct compare
{
    /**
     * @brief Porownuje dwie pary wedlug czestotliwosci lub prawdopodobienstwa, a przy remisie wedlug tekstu.
     * @param l Lewa porownywana para.
     * @param r Prawa porownywana para.
     * @return true, jezeli para l powinna znalezc sie za para r w kolejce priorytetowej.
     */
    bool operator()( pair< double, string > l, pair< double, string > r );
};

// ==================================================================================================================
/**
 * @brief Analizuje efekty kodowania Huffmana i wypisuje porownanie liczby bitow.
 * @param dane Wektor symboli wraz z ich liczba wystapien lub prawdopodobienstwem.
 * @param huffman Mapa przechowujaca kody Huffmana dla poszczegolnych symboli.
 * @param iloscLiter Mapa przechowujaca liczbe wystapien lub prawdopodobienstwo dla poszczegolnych symboli.
 * @throws HuffmanException Gdy brakuje kodu Huffmana dla symbolu albo suma danych jest niepoprawna.
 */
void analizaTekstu( vector< pair< char, double > > dane, unordered_map< char, string >& huffman, unordered_map< char, double >& iloscLiter );

// ==================================================================================================================
/**
 * @brief Buduje drzewo Huffmana, wypisuje kody symboli, zakodowany tekst oraz analize zapisu.
 * @param dane Wektor symboli wraz z ich liczba wystapien lub prawdopodobienstwem.
 * @throws HuffmanException Gdy dane wejsciowe sa puste, zawieraja niepoprawne wartosci albo powtorzone symbole.
 */
void buildTree( vector< pair< char, double > > dane );

// ==================================================================================================================

#endif
