# Zadanie 6
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
canvas.pack( pady=20 )

# updateClearButton, sprawdzenie czy canvas jest puste
def updateClearButton():
    if( len( canvas.find_all() ) ) > 0:
        btn_clear[ "state" ] = "normal"
    else:
        btn_clear[ "state" ] = "disabled" 

# Stworzenie funkcji, która rysuje losowe kółko w losowym miejscu
def drawCircle():
    #canvas.delete( "all" )

    diameter = random.randint( 20, 100 )

    x = random.randint( 0, widthCanvas - diameter )
    y = random.randint( 0, heightCanvas - diameter )

    canvas.create_oval( x, y, x + diameter, y + diameter, fill="red", outline="black")

    updateClearButton()

# Stworzenie funkcji clearCanvas()
def clearCanvas():
    canvas.delete( "all" )
    updateClearButton()

# Stworzenie przycisku
button_frame = tk.Frame( root )
button_frame.pack()

btn_draw = tk.Button( button_frame, text="Rysuj koło", width=20, command=drawCircle )
btn_draw.pack( side="left", padx=10 )

btn_clear = tk.Button( button_frame, text="Czyść", width=20, command=clearCanvas, state="disabled" )
btn_clear.pack( side="left", padx=10 )

# Mainloop
root.mainloop()