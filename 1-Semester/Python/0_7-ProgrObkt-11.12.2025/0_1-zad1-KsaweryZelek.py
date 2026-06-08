class Employee:
    def __init__( self, name ):
        self.name = name

    def get_salary( self ):
        return 3000
    
class Manager( Employee ):
    def get_salary(self):
        return super().get_salary() + 3000
    
# main
pracownik = Employee( "Adam" )
kierownik = Manager( "Kasia" )

print( f"Pracownik: { pracownik.name }, Wynagrodzenie: { pracownik.get_salary() }" )
print( f"Manager:   { kierownik.name }, Wynagrodzenie: { kierownik.get_salary() }" )