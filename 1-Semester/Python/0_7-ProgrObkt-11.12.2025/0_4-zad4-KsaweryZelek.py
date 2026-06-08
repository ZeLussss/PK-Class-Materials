class Person:
    def __init__( self, name ):
        self.name = name

class Employee( Person ):
    def __init__( self, name, salary ):
        super().__init__( name )

        self.salary = salary

class Programmer( Employee ):
    def __init__( self, name, salary, language ):
        super().__init__( name, salary )

        self.language = language

    def info( self ):
        return f"Programista { self.name } zarabia { self.salary } i koduje w { self.language }."
    
# main
dev = Programmer( "Kamil", 12000, "Python" )

print( dev.info() )