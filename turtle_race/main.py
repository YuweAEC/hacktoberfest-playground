from turtle import Turtle, Screen
import random


def draw_finish_line():
    finish_line = Turtle("square")
    finish_line.penup()
    finish_line.speed("fastest")
    finish_line.pencolor("black")
    finish_line.pensize(5)
    x = 200
    y = 180

    for _ in range(9):
        finish_line.goto(x, y)
        finish_line.stamp()
        x += 20
        y -= 20
        finish_line.goto(x, y)
        finish_line.stamp()
        x -= 20
        y -= 20
        finish_line.goto(x, y)
        finish_line.stamp()


class TurtleRace:
    def __init__(self):
        self.bg_images = [
            "./backgrounds/bg_1.gif",
            "./backgrounds/bg_2.gif",
            "./backgrounds/bg_3.gif",
            "./backgrounds/bg_4.gif",
            "./backgrounds/bg_5.gif",
        ]
        self.screen = Screen()
        self.is_race_on = False
        self.colors = ["red", "orange", "yellow", "green", "blue", "purple"]
        self.turtle_images = [
            "./images/red.gif",
            "./images/orange.gif",
            "./images/yellow.gif",
            "./images/green.gif",
            "./images/blue.gif",
            "./images/purple.gif"
        ]
        self.all_turtles = []
        self.writer = Turtle()
        self.writer.hideturtle()
        self.writer.penup()
        self.setup_screen()
        self.user_bet = self.get_user_bet()

    def get_random_background(self):
        return random.choice(self.bg_images)

    def setup_screen(self):
        self.screen.setup(width=500, height=400)
        self.screen.bgpic(self.get_random_background())
        self.screen.title("Turtle Race")

    def get_user_bet(self):
        while True:
            user_bet = self.screen.textinput(
                title="Make your bet",
                prompt="Which turtle will win the race? (Red, Blue, Green, Yellow, Purple, Orange) Enter a color: "
            )
            if user_bet.lower() in self.colors:
                return user_bet.lower()
            else:
                user_bet = self.screen.textinput(title="Please enter a valid color.",
                                                 prompt="Which turtle will win the race? (Red, Blue, Green, Yellow, Purple, Orange) Enter a color: ")
                return user_bet.lower()

    def create_turtles(self):
        y_positions = [-70, -40, -10, 20, 50, 80]

        for image in self.turtle_images:
            self.screen.register_shape(image)

        for turtle_index in range(len(self.turtle_images)):
            new_turtle = Turtle(shape=self.turtle_images[turtle_index])
            new_turtle.penup()
            new_turtle.goto(x=-230, y=y_positions[turtle_index])
            new_turtle.color(self.colors[turtle_index])
            self.all_turtles.append(new_turtle)

    def start_race(self):
        if self.user_bet:
            self.is_race_on = True
            self.create_turtles()
            draw_finish_line()

            while self.is_race_on:
                for turtle in self.all_turtles:
                    if turtle.xcor() > 190:
                        self.is_race_on = False
                        self.declare_winner(turtle)
                        break
                    random_distance = random.randint(0, 10)
                    turtle.forward(random_distance)

    def declare_winner(self, winning_turtle):
        winning_color = winning_turtle.pencolor()
        self.writer.hideturtle()
        self.writer.penup()
        self.writer.goto(0, 0)
        self.writer.pencolor("green" if winning_color == self.user_bet else "red")
        message = f"You Won! The {winning_color} turtle is the winner." if winning_color == self.user_bet else f"You've Lost! The {winning_color} turtle is the winner."
        self.writer.write(message, align="center", font=('Arial', 14, 'normal'))
        print(message)


if __name__ == "__main__":
    race = TurtleRace()
    race.start_race()
    race.screen.exitonclick()
