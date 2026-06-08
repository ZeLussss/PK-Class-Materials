# Autor: Ksawery Zelek

class Student:
    def __init__( self ):
        self.__grades = []

    def add_grade( self, grade ):
        if( 1 <= grade <= 5 ):
            self.__grades.append( grade )
            print( f"--- POMYSLNIE DODANO OCENE { grade } do dziennika!\n" )
        else:
            print( f"--- BLAD: OCENA MUSI BYC W ZAKRESIE OD 1 DO 5!\n" )

    def average( self ):
        if( len( self.__grades ) == 0 ):
            return 0
        
        return sum( self.__grades ) / len( self.__grades )
    
# Test

s1 = Student()
s1.add_grade( 5 )
s1.add_grade( 3 )
s1.add_grade( 6 )  
s1.add_grade( 0 )  

print( f"Średnia ocen: { s1.average() }" )
