# -----------------------------------------------
# Temat: Obsluga bledow
# Autor: Ksawery Zelek
# -----------------------------------------------

# -----------------------------------------------
# Funkcje

def dzielenie( value_1, value_2 ):
    try:
        wynik = value_1 / value_2
        return wynik
    except ZeroDivisionError:
        print( "BLAD: Nie mozna dzielic przez zero!" )
        return None
    except TypeError:
        print( "BLAD: Podano nieprawidlowy typ danych!" )
        return None
    except Exception as e:
        print( f"Wystapil nieoczekiwany blad { e }" )
        return None

# -----------------------------------------------
# Main

a = input( "Podaj pierwsza liczbe: " ) 
b = input( "Podaj druga liczbe: " ) 

try: 
    a = float( a )
    b = float( b )
    print( f"Wynik dzielenia: { dzielenie( a, b ) }" )
except ValueError:
    print( "BLAD: Wprowadz poprawne liczby!" )

print( "-----------" )
print( "Moja opinia: Wolę korzystac z funkcji obslugi wyjątków, ponieważ przy większych programach " )
print( "łatwiej jest obsłużyć oraz sprawdzać kod tą metodą, gdzie if-y musimy sami zadeklarować " )
print( "a w obsludze wyjatkow mozemy dać np //except Exception as e// i pokaze nam dokladny blad" )

# -----------------------------------------------