# Autor: Ksawery Zelek

class Engine:
    def start( self ):
        print( "Silnik został uruchomiony!" )

class Car:
    def __init__( self, brand, engine ):
        self.brand = brand
        self.engine = engine  # obiekt klasy Engine

    def start_car( self ):
        print( f"Samochód { self.brand } próbuje się uruchomić..." )
        self.engine.start()  # wykorzystanie obiektu silnika

# Test
engine1 = Engine()
car1 = Car( "Toyota", engine1 )

car1.start_car()
