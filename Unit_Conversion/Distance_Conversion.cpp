#include <stdio.h>

int main() {
    double distance;
    int choice;

    printf("Enter the distance value: ");
    scanf("%lf", &distance);

    printf("\nChoose conversion type:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Feet to Meters\n");
    printf("4. Meters to Feet\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2lf meters = %.4lf kilometers\n", distance, distance / 1000);
            break;
        case 2:
            printf("%.2lf kilometers = %.2lf meters\n", distance, distance * 1000);
            break;
        case 3:
            printf("%.2lf feet = %.4lf meters\n", distance, distance * 0.3048);
            break;
        case 4:
            printf("%.2lf meters = %.4lf feet\n", distance, distance / 0.3048);
            break;
        default:
            printf("Invalid choice. Please select between 1 and 4.\n");
    }

    return 0;
}
