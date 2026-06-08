from matplotlib import pyplot as plt

def czy_liczba( s ):
    try:
        float( s.replace(',', '.') )
        return True
    except ValueError:
        return False

plik_wyniki = input( "Podaj nazwe pliku z wynikami (np. wyniki.txt): " )
plik_nieznany = input( "Podaj nazwe pliku z nieznanym modelem (np. nmSEAK.txt): " )

# Wczytanie znanego modelu (z wyników)
with open( plik_wyniki, 'r' ) as f:
    tekst = f.read()
    # Wycinamy tylko to, co jest po słowie "dopasowania:"
    dane_str = tekst[ tekst.find("dopasowania:") + 12: ]
    liczby_wyniki = [ float( x.replace( ',', '.' ) ) for x in dane_str.split() if czy_liczba( x ) ]

# Wczytanie nieznanego modelu (z pliku nm)
with open( plik_nieznany, 'r' ) as f:
    liczby_nieznane = [ float( x.replace( ',', '.' ) ) for x in f.read().split() if czy_liczba( x ) ]

# Wycinamy wektory: dzielimy listę na pół i bierzemy 100 ostatnich elementów z obu połówek
pol_wyn = len( liczby_wyniki ) // 2
Y_znane = liczby_wyniki[ pol_wyn - 100 : pol_wyn ]
X_znane = liczby_wyniki[ len( liczby_wyniki ) - 100 : len( liczby_wyniki ) ]

pol_niezn = len( liczby_nieznane ) // 2
Y_nieznane = liczby_nieznane[ pol_niezn - 100 : pol_niezn ]
X_nieznane = liczby_nieznane[ len( liczby_nieznane ) - 100 : len( liczby_nieznane ) ]

# Rysowanie wykresu
plt.figure( figsize = ( 10, 6 ) )
plt.plot( X_znane, Y_znane, 'k-', label='Model w siatce identyfikacyjnej' )
plt.plot( X_nieznane, Y_nieznane, 'k--', label='Nieznany model silnika' )
plt.xlabel( 'X(t)' )
plt.ylabel( 'Y(t)' )
plt.legend()
plt.grid( True, linestyle=':', alpha=0.7 )
plt.show()