#16.10.2025 - Macierze

from random import randint
x = 0
suma = 0

for i in range( 1, 11 ):
    for j in range( 1, 11 ):
        for k in range( 1, 11 ):
            suma = i + j + k
            print( i, j, k )
            print( "suma = ", suma )
