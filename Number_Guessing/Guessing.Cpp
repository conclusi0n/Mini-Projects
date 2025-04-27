#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void number_guessing_game() {
    printf("Welcome to the Number Guessing Game!\n");
    
    // Generate a random number between 1 and 100
    srand(time(0));  // Seed the random number generator
    int number_to_guess = rand() % 100 + 1;
    
    int user_guess;
    int attempts = 0;
    int guessed = 0;

    while (!guessed) {
        printf("Guess a number between 1 and 100: ");
        if (scanf("%d", &user_guess) != 1) {
            printf("Please enter a valid number.\n");
            while(getchar() != '\n');  // Clear the input buffer
            continue;
        }
        attempts++;

        if (user_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high! Try again.\n");
        } else {
            guessed = 1;
            printf("Congratulations! You've guessed the number in %d attempts.\n", attempts);
        }
    }
}

int main() {
    number_guessing_game();
    return 0;
}
