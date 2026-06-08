class Employee:
    def __init__( self, name, department ):
        self.name = name
        self.department = department

    def get_salary( self ):
        return 3000
    
class Manager( Employee ):
    def __init__( self, name, department, bonus ):
        self.name = name
        self.department = super().__init__( name, department )

        self.bonus = bonus

    def get_salary(self):
        base_salary = super().get_salary()
        return base_salary + self.bonus 
    
# main
# Tworzenie zwykłego pracownika (Dział IT)
pracownik = Employee( "Jan Kowalski", "IT" )

# Tworzenie managera
# Podstawa 3000 + Bonus 4500 powinno dać 7500
kierownik = Manager( "Anna Nowak", "Sprzedaż", 4500 )

# Wypisanie wyników
print( f"Pracownik: { pracownik.name } (Dział: { pracownik.department })" )
print( f"Wynagrodzenie: { pracownik.get_salary() } PLN" )
print( "-" * 30)
print( f"Manager: { kierownik.name } (Dział: {kierownik.department })" )
print( f"Wynagrodzenie: { kierownik.get_salary() } PLN" )