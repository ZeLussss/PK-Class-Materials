# Autor: Ksawery Zelek

class User:
    def __init__( self, username, email ):
        self.__username = username
        self.__email = email

    def show( self ):
        print( "-----" )
        print( f"Username: { self.__username }" )
        print( f"Email: { self.__email }" )
        print( "-----\n" )

class Admin( User ):
    __bannedPeople = []

    def ban_user( self, user ):
        self.__bannedPeople.append( user )
        print( f"--- Pomyslnie zbanowano uzytkownika { user }!\n" )

    def showBanned( self ):
        print( "BANNED PEOPLE" )
        for i in self.__bannedPeople:
            print( f"{ i }" )
        print()

# Utworzenie uzytkownikow
u1 = User( "User123", "user123.costam@gmail.com" )
u2 = User( "Uczen.o456", "user123@gmail.com" )

u1.show()
u2.show()

admin = Admin( "Admin", "admin@op.pl" )
admin.ban_user( "User123" )
admin.ban_user( "Uczen.o456" )

admin.showBanned()

admin.show()
    