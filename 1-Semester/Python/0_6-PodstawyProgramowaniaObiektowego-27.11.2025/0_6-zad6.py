# Autor: Ksawery Zelek

class Rectangle:
    def __init__( self ):
        self.__width = 0
        self.__height = 0

    # Setter
    def set_width( self, width ):
        if( width > 0 ):
            self.__width = width
            print( f"--- Szerokosc ustawiona na { width }\n" )
        else:
            print( f"--- BLAD: Szerokosc musi byc wieksza niz 0!\n" )

    def set_height( self, height ):
        if( height > 0 ):
            self.__height = height
            print( f"--- Wysokosc ustawiona na { height }\n" )
        else:
            print( f"--- BLAD: Wysokosc musi byc wieksza niz 0!\n" )

    # F. Area
    def area( self ):
        return self.__width * self.__height
    

# Test
r = Rectangle()
r.set_width( 10 )
r.set_height( 5 )
print( f"Pole prostokąta: { r.area() }\n" )

r.set_width( -3 ) 
