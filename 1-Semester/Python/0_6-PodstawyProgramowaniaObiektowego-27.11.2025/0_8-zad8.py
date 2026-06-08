# Autor: Ksawery Zelek

class Vehicle:
    brand = ""
    max_speed = 0

    def info( self ):
        print( f"Marka: { self.brand } | Max Speed: { self.max_speed }\n" )

class Car( Vehicle ):
    doors = 0

    def info( self ):
        print( f"Marka: { self.brand } | Max Speed: { self.max_speed } | Doors: { self.doors }\n" )

# Utworzenie obiektu
car1 = Vehicle()
car1.brand = "Bugatti"
car1.max_speed = 405
car1.info()

car2 = Car()
car2.brand = "Ferrari"
car2.max_speed = 340
car2.doors = 3
car2.info()