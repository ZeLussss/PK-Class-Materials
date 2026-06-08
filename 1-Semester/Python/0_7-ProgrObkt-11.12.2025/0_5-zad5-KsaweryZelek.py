class Flyer:
    def fly( self ):
        print( "LATAMMM" )

class Swimmer:
    def swim( self ):
        print( "TOPIE SIE :((" )

class Duck(Flyer, Swimmer):
    pass  

# main
kaczka = Duck()

print( "--- Zachowanie Kaczki ---" )
kaczka.fly()   
kaczka.swim()  

print( "\n--- Kolejność poszukiwania metod (MRO) ---" )
print( Duck.mro() )