# Zadanie 3
# Autor: Ksawery Zelek

import tkinter as tk

# Utworzenie okna oraz canvas
root = tk.Tk()
root.title( "Moja aplikacja" )
root.geometry( "1000x600" )

canvas = tk.Canvas( root, width=800, height=400, bg="lightgray" )

# Tworzenie kształtów
canvas.create_rectangle( 10, 10, 200, 140, fill="lightblue" )
canvas.create_oval( 10, 160, 100, 250, fill="purple" )
canvas.create_line( 210, 70, 800, 260, fill="black", width=3 )

# expand=True -> pozwala na wycentrowanie automatyczne okna
canvas.pack( expand=True )

root.mainloop()