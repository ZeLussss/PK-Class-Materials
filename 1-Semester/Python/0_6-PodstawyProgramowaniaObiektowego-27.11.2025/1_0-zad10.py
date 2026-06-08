# Autor: Ksawery Zelek

class Car:
    _count = 0

    def __init__( self, brand, model ):
        self.brand = brand
        self.model = model
        Car._count += 1

    # Metoda oznaczona @classmethod działa na klasie i jako pierwszy argument przyjmuje cls (zamiast self), który reprezentuje samą klasę
    @classmethod
    def how_many( cls ):
        return( f"Liczba utworzonych samochodow -> { cls._count }\n" )
    
c1 = Car( "Toyota", "Corolla" )
c2 = Car( "Peugeot", "307" )
c3 = Car( "Hyundai", "Sonata" )

print( Car.how_many() )