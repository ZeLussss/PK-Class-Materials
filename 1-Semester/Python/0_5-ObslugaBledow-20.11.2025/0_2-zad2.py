# ----------------------------
# Zadanie 2

def to_int( s ):
    try: 
        if( s.strip() == "" ):
            print( "BLAD: Brak danych" )
            return None 

        newValue = int( s )
        return( newValue )
    
    except ValueError:    
        print( "BLAD: Nie mozna zamienic na liczbe" )
        return None

    except OverflowError:
        print( "BLAD: Overflow" )
        return None

# ----------------------------

napis = input( "Podaj String ktorego zamienimy na liczbe: " )

x = to_int( napis )

print( x )
print( type( x ) )

# ----------------------------
# W tym zadaniu nauczylem sie uzywac kolejnych typow bledow takich jak OverFlowError oraz jak najlepiej 
# sprawdzic czy string jest pusty
# ----------------------------