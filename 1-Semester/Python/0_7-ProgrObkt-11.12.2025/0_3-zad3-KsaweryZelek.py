class Vehicle:
    def move():
        print( "Pojazd się porusza" )

class Car( Vehicle ):
    def move():
        print( "Pojazd na czterech kółkach jedzie" )

class Bike( Vehicle ):
    def move():
        print( "Pojazd porusza się za pomocą dwóch kół" )

# main
print( "-" * 30 )

Vehicle.move()
print( "-" * 30 )

Car.move()
print( "-" * 30 )

Bike.move()
print( "-" * 30 )
