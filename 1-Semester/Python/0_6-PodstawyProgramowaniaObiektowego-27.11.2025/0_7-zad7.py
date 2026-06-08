# Autor: Ksawery Zelek

class Animal:
    def speak( self ):
        print( "Zwierze wydaje dzwiek!\n" )

class Dog( Animal ):
    def speak( self ):
        print( "Pies szczeka: hau, hau!\n" )

class Cat( Animal ):
    def speak( self ):
        print( "Kot miuczy: meow, meow\n" )

# Lista zwierzat
animals = [ Dog(), Cat(), Animal() ]

# Pętla
for i in animals:
    i.speak()