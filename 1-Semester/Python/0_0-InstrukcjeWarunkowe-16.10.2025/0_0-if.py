# 16.10.2025 - Lab1
from random import randint

def jakaLiczba( liczba ):
    print( "--- Twoja liczba: ", x, " ---")
    if( liczba > 10 ):
        print( "Liczba jest wieksza od 10" )
    elif( liczba > 5 and liczba < 10 ):
        print( "Liczba jest wieksza od 5, ale mniejsza od 10" )
    elif( liczba > 0 and liczba < 5 ):
        print("Liczba jest wieksza od 0, ale mniejsza od 5")
    elif ( liczba < 0 ):
        print("Liczba jest mniejsza od 0")
    else:
        print("Liczba jest z przedziału granicznego")

x = randint(-20, 20)

print( "--- Twoja liczba: ", x, " ---" )

if( x > 10 ):
    print( "Liczba jest wieksza od 10" )
elif( x > 5 and x < 10 ):
    print( "Liczba jest wieksza od 5, ale mniejsza od 10" )
elif( x > 0 and  x < 5 ):
    print( "Liczba jest wieksza od 0, ale mniejsza od 5" )
elif( x < 0 ):
    print( "Liczba jest mniejsza od 0" )
else:
    print( "Liczba jest z przedziału granicznego" )