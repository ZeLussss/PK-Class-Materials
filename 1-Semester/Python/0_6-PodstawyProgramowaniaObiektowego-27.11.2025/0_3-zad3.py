# Autor: Ksawery Zelek

class Person:
    def __init__( self, name, age ):
        self.name = name
        self.age = age

    def introduce( self ):
        print( f"Mam na imie { self.name } i mam { self.age } lat" )

# Dwa obiekty klasy person
person1 = Person( "Anna", 22 )
person2 = Person( "Jan", 25 )

# Wywołanie metody introduce
person1.introduce()
person2.introduce()