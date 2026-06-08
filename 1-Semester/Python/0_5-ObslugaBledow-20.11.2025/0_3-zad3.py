# ----------------------------
# Zadanie 3

text = ''

try:
    with open( "0_3-zad3.txt", "r", newline='', encoding="utf-8" ) as f:
        firstLine = f.readline()
        text = firstLine

except FileNotFoundError:
    print( "BLAD: Nie znaleziono pliku" )

finally:
    print( "Zakonczono probe odczytu pliku" )
    print( "Tekst: ", text )

# ----------------------------
# W tym zadaniu nauczyłem się jak skorzystac z obslugi wyjatkow FileNotFoundError
# ----------------------------