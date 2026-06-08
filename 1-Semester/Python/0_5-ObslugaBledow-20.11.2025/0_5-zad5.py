# ----------------------------
# Zadanie 5

def safe_open( filename ):
    try:
        f = open( filename, "r" )
        return f
    
    except FileNotFoundError:
        print( "BLAD: Nie znaleziono pliku" )  
        return None
    
    except Exception as e:
        print( f"BLAD: { e }" )

# ----------------------------

x = safe_open( "0_5-zad5.txt" )
if( x != None ):
    firstLine = x.readline()
    print( f"Wynik: { firstLine }" )

x.close()

y = safe_open( "LosowyTekst.txt" )
if( y != None ):
    firstLine = y.readline()
    print( f"Wynik: { firstLine }" )


# ----------------------------
# W tym zadaniu nauczylem sie jak zwracać uchwyty do plików przez funkcje.
# ----------------------------