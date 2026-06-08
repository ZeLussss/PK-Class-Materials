def dodawanieDowolnejIlosci( *arg ):
    suma = 0
    for i in arg:
        suma += i

    print( f"Suma liczb { arg } to { suma }" )

def mnozenieDowolnejIlosci( *arg ):
    suma = 0
    for i in arg:
        suma *= i

    print( f"Wynik mnożenia liczb { arg } to { suma }" )

def indeksowanieListyWypisanie( **list ):
    for indeks, wartosc in enumerate( list ):
        print( f"|\t{ indeks }: { wartosc }" )

def indeksowanieListyPrzypisanie( **list ):
    return tuple( enumerate( list ) )