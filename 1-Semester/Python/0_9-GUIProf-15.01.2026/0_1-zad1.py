# ZADANIE 1
# Autor: Ksawery Zelek

import tkinter as tk

class Player:
    def __init__(self, canvas, x, y, size=50, color="blue"):
        """
        Inicjalizacja gracza.
        :param canvas: obiekt płótna (tk.Canvas), na którym rysujemy
        :param x: początkowa pozycja X
        :param y: początkowa pozycja Y
        """
        self.canvas = canvas
        
        # Rysuje prostokąt w podanej pozycji.
        # create_rectangle przyjmuje współrzędne: (x1, y1, x2, y2)
        # Zapisujemy ID obiektu, aby móc się do niego później odwołać.
        self.id = canvas.create_rectangle(x, y, x + size, y + size, fill=color)

    def move(self, dx, dy):
        """
        Przesuwa gracza o wektor (dx, dy).
        """
        self.canvas.move(self.id, dx, dy)

# --- CZĘŚĆ TESTOWA (Aby zobaczyć jak to działa) ---

if __name__ == "__main__":
    # Tworzenie głównego okna
    root = tk.Tk()
    root.title("Zadanie: Klasa Player")

    # Tworzenie płótna (Canvas)
    canvas = tk.Canvas(root, width=400, height=400, bg="white")
    canvas.pack()

    # Tworzenie obiektu klasy Player (przekazujemy canvas i pozycję 100, 100)
    player = Player(canvas, 100, 100)

    # Funkcja obsługująca klawiaturę do testowania metody move()
    def key_handler(event):
        step = 10
        if event.keysym == 'Up':
            player.move(0, -step)
        elif event.keysym == 'Down':
            player.move(0, step)
        elif event.keysym == 'Left':
            player.move(-step, 0)
        elif event.keysym == 'Right':
            player.move(step, 0)

    # Podpięcie klawiatury pod okno
    root.bind("<Key>", key_handler)

    # Uruchomienie pętli programu
    root.mainloop()