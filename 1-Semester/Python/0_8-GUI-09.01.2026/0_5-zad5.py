# Zadanie 5
# Autor: Ksawery Zelek

import tkinter as tk
import random

# Stworzenie glownego okna
root = tk.Tk()
root.title( "Program w Python" )
root.geometry( "1000x700" )

# Stworzenie canvas
widthCanvas = 800
heightCanvas = 600
canvas = tk.Canvas( root, width=widthCanvas, height=heightCanvas, bg="lightgray" )

# canvas.pack
canvas.pack()

# Stworzenie funkcji, która rysuje losowe kółko w losowym miejscu
def drawCircle():
    canvas.delete( "all" )

    diameter = random.randint( 20, 100 )

    x = random.randint( 0, widthCanvas - diameter )
    y = random.randint( 0, heightCanvas - diameter )

    canvas.create_oval( x, y, x + diameter, y + diameter, fill="red", outline="black")

# Stworzenie prz\\ycisku
button = tk.Button( root, text="Rysuj koło", width=40, command=drawCircle )

button.pack( pady=20 )

# Mainloop
root.mainloop()