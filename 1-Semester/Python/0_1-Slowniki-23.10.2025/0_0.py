from random import randint

# --------------
# Deklaracja slownika ~ Zad 1
slownik = { 
    "A": 15, 
    "B": 20, 
    "C": 5, 
    "D": -20, 
    "E": 67 
}
# --------------

# --------------
# Zad 2
print( "Wydrukowanie slownika" )

for i in slownik:
    print( "Klucz:", i, ", Wartosc:", slownik[ i ] )
print()
# --------------

# --------------
# Zad 3
print( "Zmiana wartosci i kluczu w slowniku" )

print( "D:", slownik[ "D" ] )
slownik[ "D" ] = 20; 
print( "D:", slownik[ "D" ] )

# Można zmienić klucz w taki sposob, ze deklarujemy nowa wartosc, a pozniej poprzednia usuwamy
slownik[ "Z" ] = slownik[ "D" ]
del slownik[ "D" ]

# Próba wydrukowania
# print( "D:", slownik[ "D" ] ) !!!! NIE MOŻNA NIE ISTNIEJE
print( "Z:", slownik[ "Z" ] )
print()
# --------------

# --------------
# Zad 4
print( "Petla while" )


z = False                       # Z - oznacza warunek zakończenia pętli ~ znalezienie tej samej liczby randomValue = inputValue
while( z == False ):

    x = False                   # X - oznacza warunek zakonczenia petli ~ walidacja liczb, aby zmienna inputValue była liczbą oraz była w zakresie od <1,11>
    while (x == False):

        randomValue = randint( 1, 11 )
        
        try:
            inputValue = int(input("Podaj losową liczbę w przedziale od 1 do 11: "))
            x = True
        except ValueError:
            print("❌ Twoja liczba nie jest liczbą! PODAJ LICZBĘ PONOWNIE ❌")
            print()
            x = False
            continue  # wraca na początek, żeby nie sprawdzać inputValue, którego nie ma

        if (inputValue < 1 or inputValue > 11):
            print("Twoja wartość jest poza zakresem <1,11> ‼️‼️")
            print()
            y = False
            while (y == False):
                try:
                    inputValue = int(input("Podaj losową liczbę ❕W PRZEDZIALE <1,11>❕: "))
                    print()
                    if (inputValue < 1 or inputValue > 11):
                        print("❌ Liczba nadal nie jest w zakresie <1,11> ❌")
                        print()
                        y = False
                        continue
                    y = True
                except ValueError:
                    print("❌ Twoja liczba nie jest liczbą! PODAJ LICZBĘ PONOWNIE ❌")
                    print()
                    y = False
                    continue

    if( inputValue < randomValue ):
        print( f"Twoja wartosc {inputValue} jest mniejsza od {randomValue}" )
        z = False

    elif( inputValue > randomValue ):
        print( f"Twoja wartosc {inputValue} jest wieksza od {randomValue}" )
        z = False

    elif( inputValue == randomValue ):
        print( f"GRATULACJE! Twoja liczba {inputValue} jest rowna liczbie losowej" )
        z = True

    print()

    
# --------------




