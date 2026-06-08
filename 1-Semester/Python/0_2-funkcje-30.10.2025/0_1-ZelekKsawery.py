line = str( "----------------" )

# -----------------------------------------------------------
#                       Zadanie 1
# -----------------------------------------------------------

from math import sin

print( f"{ line }\nZadanie1\n{ line }\n" )

print( f"Wartosc sin( 90 ) = { sin( 90 ) }" )
print( f"Wartosc sin( 45 ) = { sin( 45 ) }" )
print( f"Wartosc sin( 30 ) = { sin( 30 ) }" )
print( '\n' ) 

# -----------------------------------------------------------
#                       Zadanie 2
# -----------------------------------------------------------

print( f"{ line }\nZadanie2\n{ line }\n" )

# Zaimportowanie wlasnego modulu z innego katalogu, mozna zaimportowac wszystko lub osobne moduly
import sys
sys.path.append( '' )
from Moduly.ModulKsaweryZelek import dodawanieDowolnejIlosci as dodawanie
from Moduly.ModulKsaweryZelek import mnozenieDowolnejIlosci as mnozenie
from Moduly.ModulKsaweryZelek import indeksowanieListyWypisanie as indexPrint
from Moduly.ModulKsaweryZelek import indeksowanieListyPrzypisanie as indexAssignment

dodawanie( 4, 5, 6, 7, 2, 3, 0, 1, 2 )
print()

mnozenie( 3, 4, 7, 1, 2, 8, 20, 10 )
print()

lista = [ "Imie", "Raz dwa trzy", 1, "aoaoao" ]

# Przypisanie listy z indeksami do nowej zmiennej
lista1 = indexAssignment( lista )

# Wyprintowanie indeksowanej listy bez zmiany oryginalnej wartosci
indexPrint( lista )
