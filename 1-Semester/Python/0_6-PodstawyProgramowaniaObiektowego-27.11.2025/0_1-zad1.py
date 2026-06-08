# Autor: Ksawery Zelek

class Person:
    name = ""
    age = int

    def introduce( self ):
        print( f"Mam na imie { self.name } i mam { self.age } lat" )

# Dwa obiekty klasy person
person1 = Person()
person1.name = "Ksawery"
person1.age = 20

person2 = Person()
person2.name = "Mateusz"
person2.age = 18

# Wywołanie metody introduce
person1.introduce()
person2.introduce()