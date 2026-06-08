# ---------------------------------------------------
# Imię i Nazwisko: Ksawery Zelek
# Temat: Odczyt i zapis z pliku - Plik CSV
# Data: 13.11.2025
# ---------------------------------------------------
import csv              
import json
import pickle
import os               # Importowanie potrzebnych bibliotek

'''
Przykładowe dane:
dane.csv:
Imie,Nazwisko,Wiek,Jezyki
Ksawery,Zelek,20,"['C++', 'Python']"
Anna,Kowalska,25,"['Java', 'Python']"
Jan,Nowak,30,"['JavaScript', 'PHP']"
Maria,Wiśniewska,28,"['Python', 'C#']"
Piotr,Zając,22,"['Assembly', 'C']"
Katarzyna,Mazur,27,"['Ruby', 'Python']"
Tomasz,Lewandowski,35,"['Go', 'Java']"
Magdalena,Wójcik,24,"['Swift', 'Kotlin']"
Paweł,Kamiński,29,"['Rust', 'Python']"
Joanna,Krawczyk,26,"['TypeScript', 'JavaScript']"
'''

# ---------------------------------------------------
#               WCZYTANIE DANYCH
# ---------------------------------------------------

def wczytajDane( nazwaPliku ):
    # Sprawdzenie rozszerzenia
    ext = os.path.splitext( nazwaPliku )[ 1 ].lower()

    if ext == ".csv":
        return wczytaj_CSV( nazwaPliku )
    elif ext == ".json":
        return wczytaj_JSON( nazwaPliku )
    elif ext == ".pkl" or ext == ".pickle":
        return wczytaj_PICKLE( nazwaPliku )
    else:
        raise ValueError( "Nieobslugiwany format pliku" )
    
'''
    Funkcja wczytajDane() ma w argumencie funkcji podaną nazwę pliku.
    Potem w następnych operacjach splitujemy tekst nazwyPliku, aby wydobyć rozszerzenie pliku.
    Później z takimi danymi możemy już wywołać nasze funkcje (czyt. wczytaj_CSV() itd. )
    Jeżeli rozszerzenie się nie zgadza wyrzuca błąd ValueError( "Nieobslugiwany format pliku" )
'''
    
def wczytaj_CSV( nazwaPliku ):
    dane = []
    with open( nazwaPliku, newline="", encoding="utf-8" ) as f:
        reader = csv.reader( f )
        header = next( reader )
        for row in reader:
            dane.append( row )

    return { "header": header, "rows": dane }
    
def wczytaj_JSON( nazwaPliku ):
    with open( nazwaPliku, "r", encoding="utf-8" ) as f:
        dane = json.load( f )

    return dane

def wczytaj_PICKLE( nazwaPliku ):
    with open( nazwaPliku, "rb" ) as f:
        dane = pickle.load( f )
    
    return dane

'''
    Nasze funkcje wczytaj_...() służą do wczytania danych do jakiejsc tablicy, którą później zwracamy.
    Ważne jest użycie return { "header": header, "rows": dane } w funkcji wczytaj_CSV(),
    ponieważ dzięki temu zwracamy dane w ustrukturyzowanej formie. Nagłówki i wiersze w jednym obiekcie (słowniku), 
    co ułatwia późniejsze przetwarzanie i dostęp do konkretnych elementów.
'''

def zapisz_CSV( nazwa_pliku, dane ):
    with open( nazwa_pliku, "w", newline="", encoding="utf-8" ) as f:
        writer = csv.writer( f )
        if "header" in dane:
            writer.writerow( dane[ "header" ] )
            writer.writerows( dane[ "rows" ] )
        else:
            # Jeśli dane są listą słowników
            keys = dane[ 0 ].keys()
            writer.writerow( keys )
            for row in dane:
                writer.writerow( row.values() )

'''
    Funkcja zapisz_CSV() służy do zapisania danych do pliku w formacie CSV.
    Na samym początku funkcja otwiera plik csv w trybie zapisu.
    Potem funkcja zwarca uwagę, czy nie ma przypadkiem klucza "header" w danych.
    Jeżeli nie ma traktuje dane jako listę słowników, pobierając przy tym
    1 wiersz jako nagłowki i dalsze jako dane
'''

def zapisz_JSON( nazwa_pliku, dane ):
    with open( nazwa_pliku, "w", encoding="utf-8" ) as f:
        json.dump( dane, f, indent=4, ensure_ascii=False )

def zapisz_PICKLE( nazwa_pliku, dane ):
    with open( nazwa_pliku, "wb" ) as f:
        pickle.dump( dane, f )

'''
    Funkcje zapisz_JSON() oraz zapisz_PICKLE() działają bardzo analogicznie.
    Różnica jest przy wyborze opcji otwarcia pliku. Przy JSON jest to zwykły tryb write ("w")
    natomiast przy plikach typu PICKLE jest to tryb write binary ("wb") 
'''

# ---------------------------------------------------------------
#                   GŁÓWNY PROGRAM
# ---------------------------------------------------------------

'''
    Główny program wczytuje na samym początku nazwe pliku jako (nazwa.rozszerzenie).
    Następnie wysyła te dane do funkcji wczytajDane() z argumentem nazwy pliku.
    Potem w tej funkcji typ rozszerzenia jest sprawdzany, i są wywoływane odpowiednie funkcje wczytujące dane.
    Natępnie te dane są printowane aby zobaczyć czy na pewno dane są dobrze zapisane.
    Następnym etapem zadania jest zapisanie danych do wszystkich typów plików (.csv, .json, .pkl)
'''

nazwa = input( "Podaj nazwę pliku (.csv, .json, .pkl): " )

try:
    wynik = wczytajDane( nazwa )
    print( "Dane z pliku:" )
    print( wynik )


# Tworzenie plików w trzech formatach
    zapisz_CSV( "dane.csv", wynik )
    zapisz_JSON( "dane.json", wynik )
    zapisz_PICKLE( "dane.pkl", wynik )

    print( "Pliki dane.csv, dane.json, dane.pkl zostały utworzone." )

except Exception as e:
    print( "Błąd:", e )