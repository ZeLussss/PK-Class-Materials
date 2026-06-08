# ----------------------------
# Zadanie 4

import csv

rows = []

try: 
    with open( "0_4-zad4.csv", "r", encoding="utf-8" ) as f:
        reader = csv.reader( f )

        i = 0
        for row in reader:
            i += 1
            print( row[ 0 ], " --- ", row[ 1 ] )
            try:
                wiek = int( row[ 1 ] )
                rows.append( row )
                    
            except ValueError:
                 print( f"BLAD W WIERSZU { i }: Wiek nie jest liczba" )

            except Exception as e:
                print( f"BLAD: { e }" )

except FileNotFoundError:
    print( "BLAD: Nie znaleziono pliku" )

finally:
    print( "Wynik:", rows )

# ----------------------------
# To zadanie bylo bardzo fajne. Nauczylem sie wykorzystywac wyjątki przy walidacji plików csv.
# ----------------------------