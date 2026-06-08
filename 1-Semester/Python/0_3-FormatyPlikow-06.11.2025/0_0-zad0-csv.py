# ----------------------------------------------------------------------------------------------
# Autor: Ksawery Zelek
# Tytuł: Pliki csv - Odczyt i zapis
# Data: 06.11.2025
# ----------------------------------------------------------------------------------------------
import csv 

# Nagłówki
header = [ "Imie", "Wiek", "Dzial", "Czas pracy" ]

# Dane pracownikow ktore wykorzystam do utworzenia pliku csv
rows = [
    [ "Anna", 29, "HR", 3 ],
    [ "Tomasz", 35, "IT", 7 ],
    [ "Maria", 41, "HR", 10 ],
    [ "Jan", 26, "FR", 2 ],
    [ "Katarzyna", 38, "IT", 9 ],
    [ "Piotr", 33, "HR", 5 ],
    [ "Agnieszka", 45, "FR", 15 ],
    [ "Marek", 30, "IT", 4 ]
]

# ----------------------------------------------------------------------------------------------
# Zapisanie danych do pliku csv
with open( "pracownicy.csv", "w", newline='', encoding="utf-8" ) as f:
    writer = csv.writer( f )
    writer.writerow( header ) 
    writer.writerows( rows )

line = str( "----------------------------------------" )

print( f"{ line }\nPlik pracownicy.csv zostal zapisany\n{ line }" )

# Odczyt danych jako listy
print( f"\n{ line }\nOdczyt danych jako listy:" )
nowaLista = []

with open( "pracownicy.csv", "r", encoding="utf-8" ) as f:
    reader = csv.reader( f )
    header = next( reader )
    for row in reader:
        nowaLista.append( row )
        print( row )

print( "\nNowaLista: " )
print( nowaLista )

print( f"\n{ line }" )
# ----------------------------------------------------------------------------------------------

# ----------------------------------------------------------------------------------------------
# Odczyt danych jako słownik
print( f"\n{ line }\nOdczyt danych jako słownik: \n{ line }" )
nowaLista2 = []

with open( "pracownicy.csv", "r", encoding="utf-8" ) as f:
    reader = csv.DictReader( f )
    for row in reader:
        nowaLista2.append( row )
        print( f"{ row[ "Imie" ] } | Wiek: { row[ "Wiek" ] } | Dzial: { row[ "Dzial" ] } | Czas Pracy: { row[ "Czas pracy" ] } lat" )

# ENUMERATE 

print( nowaLista2 )

print( line )