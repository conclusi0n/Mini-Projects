#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define FILENAME "accounts.txt"

// Function to load accounts from the file
void load_accounts(FILE *file, char names[][MAX_NAME_LENGTH], float balances[], int *count) {
    *count = 0;
    while (fscanf(file, "%[^,],%f\n", names[*count], &balances[*count]) != EOF) {
        (*count)++;
    }
}

// Function to save accounts back to the file
void save_accounts(FILE *file, char names[][MAX_NAME_LENGTH], float balances[], int count) {
    freopen(FILENAME, "w", file);  // Reopen file in write mode to overwrite
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%.2f\n", names[i], balances[i]);
    }
}

// Function to check balance
void check_balance(char name[], char names[][MAX_NAME_LENGTH], float balances[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("\nHello, %s! Your current balance is: $%.2f\n", name, balances[i]);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw cash
void withdraw_cash(char name[], char names[][MAX_NAME_LENGTH], float balances[], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) {
            float amount;
            printf("Enter the amount to withdraw: $");
            if (scanf("%f", &amount) != 1 || amount <= 0) {
                printf("Invalid amount! Please enter a positive number.\n");
                return;
            }
            
            // Check if the user has enough balance
            if (amount > balances[i]) {
                printf("Insufficient balance!\n");
            } else {
                balances[i] -= amount;
                printf("Withdrawal successful! Your new balance is: $%.2f\n", balances[i]);
                return;
            }
        }
    }
    printf("Account not found!\n");
}

int main() {
    FILE *file = fopen(FILENAME, "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char names[100][MAX_NAME_LENGTH];  // Store account names
    float balances[100];  // Store account balances
    int count = 0;  // Number of accounts in the file
    
    // Load the account data
    load_accounts(file, names, balances, &count);

    char name[MAX_NAME_LENGTH];
    printf("Welcome to the ATM!\n");

    // Insert card (input person's name)
    printf("Please insert your card by typing your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline character

    int account_found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], name) == 0) {
            account_found = 1;
            break;
        }
    }

    if (account_found) {
        printf("\nWelcome back, %s!\n", name);

        while (1) {
            // ATM menu
            printf("\nPlease choose an option:\n");
            printf("1. Check Balance\n");
            printf("2. Withdraw Cash\n");
            printf("3. Exit\n");
            printf("Enter your choice (1/2/3): ");
            
            int choice;
            if (scanf("%d", &choice) != 1) {
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
                while(getchar() != '\n');  // Clear input buffer
                continue;
            }

            if (choice == 1) {
                check_balance(name, names, balances, count);
            } else if (choice == 2) {
                withdraw_cash(name, names, balances, count);
                save_accounts(file, names, balances, count);  // Save the updated data after withdrawal
            } else if (choice == 3) {
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            } else {
                printf("Invalid choice. Please select again.\n");
            }
        }
    } else {
        printf("Sorry, the account name is not found. Please try again.\n");
    }

    fclose(file);  // Close the file
    return 0;
}

// DIdn't did on own , Use AI to generate most of the code and then added some of my own code to make it work