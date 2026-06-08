# Zadanie 4
# Autor: Ksawery Zelek

import tkinter as tk

# Utworzenie okna oraz canvas
root = tk.Tk()
root.title( "Moja aplikacja" )
root.geometry( "1000x600" )

canvas = tk.Canvas( root, width=800, height=400, bg="lightgray" )

# Tworzenie napisu
canvas.create_text( 400, 200, font=( "Helvetica", 30 ), text="Python Graphics", fill="green" )

# expand=True -> pozwala na wycentrowanie automatyczne okna
canvas.pack( expand=True )

root.mainloop()