import random

def number_guessing_game():
    print("Welcome to the Number Guessing Game!")
    
    # Generate a random number between 1 and 100
    number_to_guess = random.randint(1, 100)
    
    attempts = 0
    guessed = False

    while not guessed:
        try:
            user_guess = int(input("Guess a number between 1 and 100: "))
            attempts += 1
            
            if user_guess < number_to_guess:
                print("Too low! Try again.")
            elif user_guess > number_to_guess:
                print("Too high! Try again.")
            else:
                guessed = True
                print(f"Congratulations! You've guessed the number in {attempts} attempts.")
        
        except ValueError:
            print("Please enter a valid number.")

# Start the game
if __name__ == "__main__":
    number_guessing_game()
