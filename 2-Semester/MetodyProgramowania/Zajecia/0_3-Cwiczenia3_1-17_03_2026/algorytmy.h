#ifndef ALGORYTMY_H
#define ALGORYTMY_H

#include <fstream>

using namespace std;

long long zliczElementy( long long* tab, int size, long long value );
int wyszukiwanieInterpolacyjne( long long* tab, int size, long long value );
void wypiszBezDuplikatow( ofstream& outFile, long long* tab, int size );
void przetworzZestaw( ifstream& inFile, ofstream& outFile, long long* tab, int size );

#endif