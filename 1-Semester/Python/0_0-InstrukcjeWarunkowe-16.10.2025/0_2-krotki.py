listaImion = list(( "Ksawery", "Mikołaj", "Adam", "Bartek", "Andrzej" ))

listaImionKrotka = ( "Ksawery", "Mikołaj", "Adam", "Bartek", "Andrzej" )

print("----- Przed zmianami -----" )
print()

print( "Lista" )
x = 1
for i in listaImion:
    print( x, ": ", i )
    x += 1

print()
print( "Krotki" )
x = 1
for i in listaImionKrotka:
    print( x, ": ", i )
    x += 1

#Zmiany             !!!!

#lista
listaImion[ 2 ] = "Mateusz"
listaImion[ 4 ] = "Ola"

print()
print("----- Po zmianach -----")
print()

print("Lista")
x = 1
for i in listaImion:
    print(x, ": ", i)
    x += 1

#krotki
listaImionKrotka[ 2 ] = "Mateusz"
listaImionKrotka[ 4 ] = "Ola"

print()
print("Krotki")
x = 1
for i in listaImionKrotka:
    print(x, ": ", i)
    x += 1
