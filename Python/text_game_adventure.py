import time

def print_slow(str):
    for char in str:
        print(char, end='', flush=True)
        time.sleep(0.05)
    print()

def intro():
    print_slow("Welcome to the Adventure Game!")
    print_slow("You find yourself in a dark forest.")
    print_slow("In front of you are two paths.")
    print_slow("Do you want to go left or right?")

def choose_path():
    choice = input("Type 'left' or 'right': ").strip().lower()
    if choice == 'left':
        left_path()
    elif choice == 'right':
        right_path()
    else:
        print_slow("Invalid choice. Please choose 'left' or 'right'.")
        choose_path()

def left_path():
    print_slow("You chose the left path.")
    print_slow("You encounter a friendly dragon!")
    action = input("Do you want to 'talk' to the dragon or 'run' away? ").strip().lower()
    if action == 'talk':
        print_slow("The dragon gives you a treasure chest! You win!")
    elif action == 'run':
        print_slow("You safely escape, but miss out on the treasure. Game over.")
    else:
        print_slow("Invalid action. Game over.")

def right_path():
    print_slow("You chose the right path.")
    print_slow("You encounter a fierce troll!")
    action = input("Do you want to 'fight' the troll or 'flee'? ").strip().lower()
    if action == 'fight':
        print_slow("The troll is too strong. You lose! Game over.")
    elif action == 'flee':
        print_slow("You run away safely. Game over.")
    else:
        print_slow("Invalid action. Game over.")

def play_game():
    intro()
    choose_path()

if __name__ == "__main__":
    play_game()