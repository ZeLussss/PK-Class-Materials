# Zadanie 2
# Autor: Ksawery Zelek

import tkinter as tk

# ----------------------------------------
#                   1
# ----------------------------------------

# Funkcja Tk() tworzy główne okno aplikacji
root = tk.Tk()

# Ustawienie tytułu okna
root.title( "Moja aplikacja" )

# Ustawienie rozmiaru okna
root.geometry( "600x400" )

# ----------------------------------------
#                   2
# ----------------------------------------

# Utworzenie obiektu canvas
canvas = tk.Canvas( root, width=500, height=300, bg="lightgray" )

# Umieszczenie obiektu canvas do root'a
canvas.pack()

# Uruchemienie pętle zdarzeń
root.mainloop()