import tkinter as tk
import random

class TurtleCrossingGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Turtle Crossing Game")

        self.canvas = tk.Canvas(root, width=600, height=400, bg='lightblue')
        self.canvas.pack()

        self.turtle = self.canvas.create_rectangle(275, 350, 325, 400, fill='green')
        self.cars = []
        self.car_speed = 5
        self.score = 0

        self.root.bind("<Left>", self.move_left)
        self.root.bind("<Right>", self.move_right)

        self.create_cars()
        self.update_cars()

    def create_cars(self):
        for _ in range(5):
            x = random.randint(0, 550)
            car = self.canvas.create_rectangle(x, random.randint(50, 300), x + 50, random.randint(50, 300) + 20, fill='red')
            self.cars.append(car)

    def move_left(self, event):
        self.canvas.move(self.turtle, -20, 0)
        self.check_collision()

    def move_right(self, event):
        self.canvas.move(self.turtle, 20, 0)
        self.check_collision()

    def update_cars(self):
        for car in self.cars:
            self.canvas.move(car, -self.car_speed, 0)
            if self.canvas.coords(car)[0] < 0:
                self.canvas.move(car, 600, 0)
                self.canvas.coords(car, random.randint(0, 550), random.randint(50, 300), random.randint(0, 550) + 50, random.randint(50, 300) + 20)

        self.check_collision()
        self.root.after(100, self.update_cars)

    def check_collision(self):
        for car in self.cars:
            if self.is_collision(car):
                self.game_over()
                return
        if self.canvas.coords(self.turtle)[1] < 0:
            self.score += 1
            self.canvas.coords(self.turtle, 275, 350, 325, 400)
            self.canvas.create_text(300, 200, text="Score: {}".format(self.score), font=("Arial", 24), fill="black")
            self.root.update()
            self.root.after(1000, self.canvas.delete, 'all')

    def is_collision(self, car):
        car_coords = self.canvas.coords(car)
        turtle_coords = self.canvas.coords(self.turtle)

        return not (turtle_coords[2] < car_coords[0] or
                    turtle_coords[0] > car_coords[2] or
                    turtle_coords[3] < car_coords[1] or
                    turtle_coords[1] > car_coords[3])

    def game_over(self):
        self.canvas.create_text(300, 200, text="Game Over!", font=("Arial", 30), fill="black")
        self.canvas.create_text(300, 250, text="Final Score: {}".format(self.score), font=("Arial", 20), fill="black")
        self.root.update()

if __name__ == "__main__":
    root = tk.Tk()
    game = TurtleCrossingGame(root)
    root.mainloop()
