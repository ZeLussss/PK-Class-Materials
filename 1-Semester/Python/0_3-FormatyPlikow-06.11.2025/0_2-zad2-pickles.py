# ----------------------------------------------------------------------------------------------
# Autor: Ksawery Zelek
# Tytuł: Pickle (bin) - Odczyt i zapis
# Data: 06.11.2025
# ----------------------------------------------------------------------------------------------
import pickle

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
# Zapis danych do pliku Pickle
with open( "pracownicy.pkl", "wb" ) as f:
    pickle.dump( pracownicy, f )

line = '-' * 40
print( f"{ line }\nPlik pracownicy.pkl został zapisany\n{ line }" )

# ----------------------------------------------------------------------------------------------
# Odczyt danych z pliku pickle jako tekst

print( f"\n{ line }\nOdczyt danych z pliku pickle\n{ line }" )

with open( "pracownicy.pkl", "rb" ) as f:
    nowaListaPickle = pickle.load( f )
    for i, row in enumerate( nowaListaPickle, start=1 ):
        print( f"{ i }. { row[ "Imie" ] } | Wiek: { row[ "Wiek" ] } | Dzial: { row[ "Dzial" ] } | Czas pracy: { row[ "Czas pracy" ] } lat" )
print()

# ----------------------------------------------------------------------------------------------

# ----------------------------------------------------------------------------------------------
# Odczyt danych jako lista słowników

print( f"{ line }\nZawartosc pliku pickle jako lista slownikow: \n{ line }" )

print( nowaListaPickle )
print( line )

# ----------------------------------------------------------------------------------------------