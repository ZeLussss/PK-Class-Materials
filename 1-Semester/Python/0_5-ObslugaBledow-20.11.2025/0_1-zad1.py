# ----------------------------
# Zadanie 1

a = input( "Podaj pierwsza liczbe: " ) 
b = input( "Podaj druga liczbe: " )

try: 
    a = float( a )
    b = float( b )

    wynik = a / b

except ZeroDivisionError:
    print( "BLAD: Dzielenie przez zero" )

except ValueError:
    print( "BLAD: Podano zly typ danych" )

print( f"Licznik: { a }" )
print( f"Mianownik: { b }" )

# ----------------------------
# W tym zadaniu uzylem obslugi bledow takich jak ZeroDivisionError oraz ValueError
# ----------------------------