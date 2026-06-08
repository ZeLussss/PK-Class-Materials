# Autor: Ksawery Zelek
line = str( '-------------------' )

class Book:
    def __init__( self, title, author, pages ):
        self.title = title
        self.author = author
        self.pages = pages

    def info( self ):
        print( line )
        print( f"Tytul: \t{ self.title }" )
        print( f"Autor: \t{ self.author } ")
        print( f"Ma:\t{ self.pages } stron" )
        print( line )

# Tworzenie obiektow z klasą Book
book1 = Book( "Pan Tadeusz", "Adam Mickiewicz", 340 )
book2 = Book( "Lalka", "Bolesław Prus", 520 )
book3 = Book( "Wiedźmin: Ostatnie życzenie", "Andrzej Sapkowski", 288 )

# Wywołanie metody info()
book1.info()
print()

book2.info()
print()

book3.info()