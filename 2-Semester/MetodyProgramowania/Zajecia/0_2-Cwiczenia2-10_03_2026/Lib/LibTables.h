#ifndef LIBTABLES_H
#define LIBTABLES_H

using namespace std;

/**
 * Funkcja dynamicznie alokujaca pamiec dla tablicy dwuwymiarowej (wiersze x kolumny).
 * Korzysta wylacznie z wbudowanych mechanizmow zarzadzania pamiecia.
 */
double** alokujTablice( int wiersze, int kolumny );

/**
 * Funkcja zwalniajaca pamiec zaalokowana na tablice dwuwymiarowa.
 */
void zwolnijTablice( double** tablica, int wiersze );

/**
 * Funkcja obliczajaca blad sredniokwadratowy (MSE) miedzy siatka znana a nieznana.
 */
double obliczMSE( double* Y_znane, double* X_znane, double* Y_nieznane, double* X_nieznane, int liczbaDanych );

/**
 * Algorytm glowny wyznaczajacy najlepsze dopasowanie z grupy siatek,
 * zrealizowany wylacznie za pomoca wlasnych petli sprawdzajacych.
 */
void znajdzNajlepszeDopasowanie( double** siatkiZnane, int liczbaSiatek, double** siatkaNieznana, double* tablicaMSE, int& indeksNajlepszy, double& minMSE );

#endif