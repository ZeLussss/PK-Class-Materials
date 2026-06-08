# -------------------------------------------------------------------------------
#                             ZADANIE 1
# -------------------------------------------------------------------------------

wielkosciPizzy = [ 30, 45, 50, 70 ]

skladniki = [ "Salami", "Pomidor", "Ser", "Szynka" ] 

rodzajeSpodowDoPizzy = [ "Cienkie", "Grube" ]

serWBrzegach = False

# Funkcja która posiada wartosci domyslne, które wypisuje dane o zamówieniu
def zamowPizze( jakDuzaPizza = wielkosciPizzy[ 0 ], 
                skladniki = skladniki[ 0 ],
                rodzajSpodu = rodzajeSpodowDoPizzy[ 0 ],
                serWBrzegach = False ):
    print( "--------------------------" )
    print( "       TWOJA PIZZA        " )
    print( "--------------------------" )
    print( f"Wielkosc pizzy: { jakDuzaPizza }" )
    print( f"Skladnik: { skladniki }" ) 
    print( f"Jaki Spód?: { rodzajSpodu }" )
    print( f"Czy ser w brzegach?: { serWBrzegach }" )
    print()

print( "---------------\nZadanie1\n---------------\n" )

zamowPizze()
zamowPizze( wielkosciPizzy[ 2 ], skladniki[ 3 ] )
zamowPizze( wielkosciPizzy[ 3 ], skladniki[ 2 ], rodzajeSpodowDoPizzy[ 1 ] )
zamowPizze( 25, "Tuńczyk", "Grube", True )
zamowPizze( 30, "Salami", "Cienkie", False )
zamowPizze( 22, "Warzywa", "Bezglutenowe", True )
zamowPizze( jakDuzaPizza=28, skladniki="Kurczak", serWBrzegach=False )


# -------------------------------------------------------------------------------
#                               ZADANIE 2
# -------------------------------------------------------------------------------

# Funkcja, która w argumencie przyjmuje liste, i pozniej tworzy krotke, ktora jest mnozona 0, 1, 2 itp
def wartosciZKrotka( *wart ):
    wynik = tuple( wartosc * indeks for indeks, wartosc in enumerate( wart ) )
    print( wynik )

print( "---------------\nZadanie2\n---------------\n" )

wartosciZKrotka( 2, 5, 8, 1, 10, 4 )        # Musi byc bez [] poniewaz jakby przekazac z [] to przekazuje jako jedna wartosc
print( "PRZYKLAD PODANIA ARG W [] -> " )
wartosciZKrotka( [ 1, 2, 3 ] )              # Przykład
print()

# -------------------------------------------------------------------------------
#                               ZADANIE 3
# -------------------------------------------------------------------------------

print( "---------------\nZadanie3\n---------------\n" )

# Funkcja, która wypisuje dane pracownica posiadajac od niego slownik
def wartosciZLista( **wart ):
    print( "Dane pracownika" )
    for klucz, wartosc in wart.items():
        print( f"|\t{ klucz.capitalize() }: { wartosc }")

pracownik1 = {
    "Imie": "Ksawery",
    "Nazwisko": "Zelek",
    "Lat": 20,
    "Plec": "M",
    "Data Urodzenia": "2005-09-16"
}

pracownik2 = {
    "Imie": "Mateusz",
    "Nazwisko": "Zelek",
    "Lat": 18,
    "Plec": "M"
}

pracownik3 = {
    "Imie": "Kamil",
    "Nazwisko": "Zdun"
}

pracownik4 = {
    "Imie": "Tomislaw Apoloniusz Curuś",
    "Nazwisko": "Bachleda Farrel",
    "Odcinek": "138"
}



wartosciZLista( **pracownik1 )
print()

wartosciZLista( **pracownik2 )
print()

wartosciZLista( **pracownik3 )
print()

wartosciZLista( **pracownik4 )
print()