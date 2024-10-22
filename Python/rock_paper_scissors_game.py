import random

choices = ["rock", "paper", "scissors"]
computer_choice = random.choice(choices)
player_choice = input("Enter rock, paper, or scissors: ").lower()

if player_choice == computer_choice:
    print("It's a tie!")
elif (player_choice == "rock" and computer_choice == "scissors") or \
     (player_choice == "scissors" and computer_choice == "paper") or \
     (player_choice == "paper" and computer_choice == "rock"):
    print(f"You win! {player_choice} beats {computer_choice}")
else:
    print(f"You lose! {computer_choice} beats {player_choice}")
