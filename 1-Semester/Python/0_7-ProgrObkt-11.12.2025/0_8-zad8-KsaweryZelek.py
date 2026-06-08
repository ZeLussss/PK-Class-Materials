from typing import Protocol

class Drawable( Protocol ):
    def draw( self ) -> None:
        pass

class Window:
    def draw( self ) -> None:
        print( "Rysuję OKNO na ekranie." )

class Image:
    def draw( self ) -> None:
        print( "Rysuję OBRAZEK z pliku." )

def render( obj: Drawable ) -> None:
    print( f"--- Renderowanie obiektu typu { type( obj ).__name__ } ---" )
    obj.draw()

# --- Testowanie kodu ---

win = Window()
img = Image()

render( win )
render( img )