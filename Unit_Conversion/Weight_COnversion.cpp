#include <stdio.h>

int main() {
    double weight;
    int choice;

    printf("Enter the weight value: ");
    scanf("%lf", &weight);

    printf("\nChoose conversion type:\n");
    printf("1. Kilograms to Grams\n");
    printf("2. Grams to Kilograms\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2lf kilograms = %.2lf grams\n", weight, weight * 1000);
            break;
        case 2:
            printf("%.2lf grams = %.4lf kilograms\n", weight, weight / 1000);
            break;
        case 3:
            printf("%.2lf pounds = %.4lf kilograms\n", weight, weight * 0.453592);
            break;
        case 4:
            printf("%.2lf kilograms = %.4lf pounds\n", weight, weight / 0.453592);
            break;
        default:
            printf("Invalid choice. Please select between 1 and 4.\n");
    }

    return 0;
}
