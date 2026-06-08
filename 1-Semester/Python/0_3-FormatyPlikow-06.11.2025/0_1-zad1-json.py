# ----------------------------------------------------------------------------------------------
# Autor: Ksawery Zelek
# Tytuł: JSON - Odczyt i zapis
# Data: 06.11.2025
# ----------------------------------------------------------------------------------------------
import json

# Dane pracownikow jako lista slownikow
pracownicy = [
    { "Imie": "Anna",       "Wiek": 29, "Dzial": "HR", "Czas pracy": 3 },
    { "Imie": "Tomasz",     "Wiek": 35, "Dzial": "IT", "Czas pracy": 7 },
    { "Imie": "Maria",      "Wiek": 41, "Dzial": "HR", "Czas pracy": 10 },
    { "Imie": "Jan",        "Wiek": 26, "Dzial": "FR", "Czas pracy": 2 },
    { "Imie": "Katarzyna",  "Wiek": 38, "Dzial": "IT", "Czas pracy": 9 },
    { "Imie": "Piotr",      "Wiek": 33, "Dzial": "HR", "Czas pracy": 5 },
    { "Imie": "Agnieszka",  "Wiek": 45, "Dzial": "FR", "Czas pracy": 15 },
    { "Imie": "Marek",      "Wiek": 30, "Dzial": "IT", "Czas pracy": 4 }
]

# ----------------------------------------------------------------------------------------------
# Zapis danych do pliku JSON

with open( "pracownicy.json", "w", encoding="utf-8" ) as f:
    json.dump( pracownicy, f, indent=4 )

line = '-' * 40
print( f"{ line }\nPlik pracownicy.json zostal zapisany\n{ line }" )

# ----------------------------------------------------------------------------------------------

# ----------------------------------------------------------------------------------------------
# Odczyt danych z pliku JSON (wypisanie jako tekst)

print( f"\n{ line }\nOdczyt danych z pliku JSON:\n{ line }" )

with open( "pracownicy.json", "r", encoding="utf-8" ) as f:
    nowaListaJSON = json.load( f )
    for i, row in enumerate( nowaListaJSON, start=1 ):
        print( f"{ i }. { row[ "Imie" ] } | Wiek: { row[ "Wiek" ] } | Dzial: { row[ "Dzial" ] } | Czas pracy: { row[ "Czas pracy" ] } lat" )

# ----------------------------------------------------------------------------------------------

# ----------------------------------------------------------------------------------------------
# Odczyt danych z pliku JSON jako lista slownikow

print( f"{ line }\nZawartosc pliku JSON jako lista slownikow:\n { line }" )

print( nowaListaJSON )
print( line )

# ----------------------------------------------------------------------------------------------
