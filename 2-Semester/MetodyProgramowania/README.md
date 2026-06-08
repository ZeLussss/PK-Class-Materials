# Metody Programowania – Laboratoria

Repozytorium zawiera komplet programów i zadań zrealizowanych w ramach laboratorium z przedmiotu **Metody Programowania** na kierunku **Informatyka w Inżynierii Komputerowej** na Wydziale Inżynierii Elektrycznej i Komputerowej (WIEiK) Politechniki Krakowskiej.

## Spis treści i opis laboratoriów

### [Laboratorium 1] Maksymalna Podtablica (Algorytm Kadane'a)
- **Opis:** Wyznaczanie maksymalnej spójnej podtablicy (fragmentu) w dwuwymiarowej tablicy liczb całkowitych o maksymalnej sumie elementów.
- **Wymagania:** Program działający w optymalnym czasie $O((\max(n,m))^3)$ z wykorzystaniem funkcji i odpowiednich algorytmów sumowania.

### [Laboratorium 2] Analiza Modeli Silników
- **Opis:** Przetwarzanie i ekstrakcja danych z wielowymiarowych plików tekstowych (`siatkaSEAK.txt`) zawierających siatki identyfikacyjne modeli silników (elektryczny asynchroniczny klatkowy oraz bezszczotkowy). Praca na wektorach i parametrach charakterystyk.

### [Laboratorium 3] Efektywne Operacje na Tablicach & Kombinatoryka
- **Program 01:** Efektywne obliczanie krotności elementów metodą binarną $O(\log n)$, wyszukiwanie interpolacyjne indeksu zadanej wartości oraz usuwanie duplikatów z tablicy w czasie liniowym $O(n)$.
- **Dodatek:** Generowanie ciągu wszystkich podzbiorów zbioru $n$-elementowego przy użyciu kodu binarnego (w taki sposób, by kolejny podzbiór powstawał przez zmianę jednego elementu) oraz generowanie $k$-elementowych podzbiorów w porządku leksykograficznym.

### [Laboratorium 4] Parsowanie Wyrażeń i Stosy (ONP)
- **Opis:** Implementacja struktury danych stosu na trzy sposoby: w tablicy dynamicznej jednowymiarowej, za pomocą listy jednokierunkowej oraz z wykorzystaniem adaptera `std::stack`.
- **Zastosowanie:** Wykorzystanie stosu do parsowania oraz konwersji wyrażeń matematycznych pomiędzy notacją infiksową (klasyczną) a Odwróconą Notacją Polską (ONP/Postfiksową) z obsługą priorytetów i łączności operatorów.

### [Laboratorium 5] Reprezentacja i Analiza Grafów
- **Program 01:** Budowanie macierzy incydencji grafu skierowanego na bazie dynamicznej tablicy dwuwymiarowej oraz `std::vector`, wraz z wyznaczaniem sąsiadów wierzchołków.
- **Program 02:** Tworzenie tablicy list incydencji dla grafu nieskierowanego (za pomocą struktur/listy jednokierunkowej bądź `std::list`) oraz obliczanie stopni wierzchołków.

### [Laboratorium 6] Wyszukiwanie w Dwuwymiarowych Tablicach Posortowanych
- **Opis:** Implementacja algorytmów przeszukiwania w specyficznej macierzy dwuwymiarowej (gdzie każdy wiersz i kolumna są posortowane niemalejąco).
- **Metody:** Cztery niezależne funkcje o średniej złożoności czasowej ściśle mniejszej od kwadratowej ($< O(\max(n,m))$): rekurencyjna (pierwsze i ostatnie wystąpienie) oraz iteracyjna (pierwsze i ostatnie wystąpienie leksykograficznie).

### [Laboratorium 7] Generatory Liczb Pseudolosowych
- **Opis:** Implementacja oraz analiza dwóch deterministycznych metod generowania liczb losowych: liniowej metody kongruencyjnej (LCG) wraz z automatycznym wyliczaniem współczynników na podstawie wartości maksymalnej $X_{\max}$ oraz addytywnej metody kongruencyjnej. Dodatkowo porównanie z wbudowanym generatorem Mersenne Twister (`mt19937`).

### [Laboratorium 8] Problem Plecakowy (Dynamiczny i Rekurencyjny)
- **Program 01:** Rozwiązanie ogólnego problemu plecakowego (z nieograniczoną liczbą przedmiotów każdego typu) przy użyciu programowania dynamicznego (programowanie od dołu).
- **Program 02:** Dokładne wypełnianie plecaka o zadanej pojemności za pomocą czystej rekurencji bez użycia pętli (znajdowanie dokładnej sekwencji wag), wraz z obsługą wyjątków.

### [Laboratorium 9] Algorytmy z Powrotami (Backtracking)
- **Opis:** Rozwiązanie dyskretnego problemu plecakowego 0-1 (decyzyjnego) zorientowanego na maksymalizację zysku przy użyciu algorytmu przeszukiwania drzewa stanów z powrotami (*backtracking*). Program generuje raport tekstowy pokazujący krok po kroku operacje na węzłach drzewa.

### [Laboratorium 10] Kodowanie Huffmana & Obsługa Wyjątków
- **Opis:** Konstrukcja optymalnego binarnego kodu prefiksowego dla podanego zestawu znaków/liter na podstawie ich częstotliwości występowania bądź prawdopodobieństwa (Algorytm Huffmana).
- **Wymagania:** Implementacja własnej, dedykowanej klasy wyjątków (dziedziczącej np. po `std::runtime_error`) w celu zabezpieczenia i walidacji danych wejściowych algorytmu.

---

## Struktura i Standardy Kodu

Wszystkie programy spełniają poniższe kryteria akademickie i techniczne:
- **Podział na moduły:** Logiczna separacja kodu na pliki nagłówkowe (`.h`) oraz pliki źródłowe (`.cpp`).
- **Obsługa błędów:** Zabezpieczenia strumieni wejściowych oraz obsługa wyjątków tam, gdzie wymaga tego specyfikacja.
- **Styl pisania:** Czytelny kod zawierający wyczerpujące komentarze wyjaśniające działanie i złożoność zaimplementowanych algorytmów.

## Kompilacja i Uruchomienie

Większość programów została przystosowana do przetwarzania danych ze standardowego wejścia lub plików tekstowych. Kompilacja przy użyciu dowolnego nowoczesnego kompilatora C++ (np. `g++` wspierającego standard C++11 lub nowszy):

```bash
# Przykład kompilacji dla wybranego laboratorium
g++ -std=c++11 *.cpp -o ProgramEXE

# Uruchomienie programu
./ProgramEXE < plik_wejsciowy.txt
```

## Autor
- **Ksawery Zelek**
- Student Informatyki w Inżynierii Komputerowej (IWiK), Wydział Inżynierii Elektrycznej i Komputerowej (WIEiK)
- Politechnika Krakowska 2026