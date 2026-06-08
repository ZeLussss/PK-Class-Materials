# Autor: Ksawery Zelek

class BankAccount:
    def __init__( self, amount ):
        self.amount = amount

    def deposit( self, amount ):
        if( amount > 0 ):
            self.amount += amount
            print( "--- OPERACJA WYKONANA\n" )

        else:
            print( "--- OPERACJA NIEUDANA, NIE DA SIE UJEMNEJ ALBO CHCIALES WPLACIC 0\n" )

    def withdraw( self, amount ):
        if( self.amount - amount >= 0 ):
            self.amount -= amount
            print( "--- OPERACJA WYKONANA\n" )

        elif( self.amount - amount < 0 ):
            print( "!!! OPERACJA NIEUDANA, BRAK WYSTARCZAJACYCH SRODKOW NA KONCIE\n" )

    def show_balance( self ):
        print( f"Twoje obecne saldo to { self.amount }!" )

# Utworzenie konta
konto = BankAccount( 1000 )

# Testy
konto.show_balance()

konto.deposit( 1500 )
konto.show_balance()

konto.deposit( -1500 )
konto.show_balance()

konto.withdraw( 1000 )
konto.show_balance()

konto.withdraw( 5000 )
konto.show_balance()