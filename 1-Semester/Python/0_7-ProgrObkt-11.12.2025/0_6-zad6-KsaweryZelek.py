from abc import ABC, abstractmethod
import math

class Shape( ABC ):
    @abstractmethod
    def area( self ):
        pass  

class Rectangle( Shape ):
    def __init__( self, width, height ):
        self.width = width
        self.height = height

    def area( self ):
        return self.width * self.height

class Circle(Shape):
    def __init__( self, radius ):
        self.radius = radius

    def area( self ):
        return math.pi * ( self.radius ** 2 )

# main

shapes = [
    Rectangle( 10, 5 ),
    Circle( 3 ),
    Rectangle( 2, 2 )
]

print( "--- Policzmy pola figur ---" )

for shape in shapes:
    print( f"Figura: { shape.__class__.__name__ }, Pole: { shape.area() }" )