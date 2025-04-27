#include <stdio.h>

int main() {
    double num1, num2;
    int choice;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("\nChoose operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
    }
    else if (choice == 2) {
        printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
    }
    else if (choice == 3) {
        printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
    }
    else if (choice == 4) {
        if (num2 == 0) {
            printf("Error: Cannot divide by zero.\n");
        } else {
            printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
        }
    }
    else {
        printf("Invalid choice. Please select between 1 and 4.\n");
    }

    return 0;
}
