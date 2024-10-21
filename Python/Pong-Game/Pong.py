"""
    @ Simple Pong Game - in Python 3
        - By 💜🐱‍👤 MS.Invisible || Gustavo H.J
"""

# Imports Requires
import turtle
import winsound

"""
    @ Case the OS from the your PC is not Windows, use:
        aplay sound.wav -> linux
        afplay sound.wav& -> Mac
"""

# Score
score_a = 0
score_b = 0

# Setup for screen game
wn = turtle.Screen()
wn.title("Pong Game - 🏓")
wn.bgcolor("black")
wn.setup(width=800, height=600)
wn.tracer(2)

# Paddle A
paddle_a = turtle.Turtle()
paddle_a.speed(0)
paddle_a.shape("square")
paddle_a.color("white")
paddle_a.shapesize(stretch_wid=5, stretch_len=1)
paddle_a.penup()
paddle_a.goto(-350, 0)

# Paddle B
paddle_b = turtle.Turtle()
paddle_b.speed(0)
paddle_b.shape("square")
paddle_b.color("white")
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup()
paddle_b.goto(350, 0)

# Ball
ball = turtle.Turtle()
ball.speed(0)
ball.shape("circle")
ball.color("white")
ball.penup()
ball.goto(0, 0)
ball.dx = 2
ball.dy = 2

# Pen
pen = turtle.Turtle()
pen.speed(0)
pen.color("white")
pen.penup()
pen.hideturtle()
pen.goto(0, 260)


# Function for tratement score to paddles
def score(a=0, b=0):
    pen.clear()

    score_finaly = "Player A: {}  || Player B: {}".format(a, b)
    pen.write(score_finaly, align="center", font=("Courier", 24, "normal"))


score(a=0, b=0)


# Functions
def paddle_a_up():
    y = paddle_a.ycor()
    y += 20
    paddle_a.sety(y)


def paddle_a_down():
    y = paddle_a.ycor()
    y -= 20
    paddle_a.sety(y)


def paddle_b_up():
    y = paddle_b.ycor()
    y += 20
    paddle_b.sety(y)


def paddle_b_down():
    y = paddle_b.ycor()
    y -= 20
    paddle_b.sety(y)


def colission_paddle_ball():
    if ball.xcor() < -340 and paddle_a.ycor() + 50 > ball.ycor() > paddle_a.ycor() - 50:
        ball.dx *= -1
        winsound.PlaySound('sound\\bounce.wav', winsound.SND_ASYNC)
    elif ball.xcor() > 340 and paddle_b.ycor() + 50 > ball.ycor() > paddle_b.ycor() - 50:
        ball.dx *= -1
        winsound.PlaySound('sound\\bounce.wav', winsound.SND_ASYNC)


def colission_top_bottom():
    if ball.ycor() > 290:
        ball.sety(290)
        ball.dy *= -1
        winsound.PlaySound('sound\\bounce.wav', winsound.SND_ASYNC)

    if ball.ycor() < -290:
        ball.sety(-290)
        ball.dy *= -1


# Keyboard binding
wn.listen()

# events keyboard paddle_a
wn.onkeypress(paddle_a_up, "w")
wn.onkeypress(paddle_a_down, "s")

# events keyboard paddle_b
wn.onkeypress(paddle_b_up, "Up")
wn.onkeypress(paddle_b_down, "Down")


# Main game looppass
while True:
    wn.update()

    # Move the ball
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    # Colission top and bottom
    colission_top_bottom()

    # Colission left and right
    if ball.xcor() > 360:
        score_a += 1
        score(a=score_a, b=score_b)

        ball.goto(0, 0)
        ball.dx *= -1
    elif ball.xcor() < -360:
        score_b += 1
        score(a=score_a, b=score_b)

        ball.goto(0, 0)
        ball.dx *= -1

    # Colission paddle and Ball colissions
    colission_paddle_ball()
