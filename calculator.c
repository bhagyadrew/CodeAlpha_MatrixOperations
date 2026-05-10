#include <stdio.h>

int main() {
    double num1, num2, result;
    int choice;

    printf("===========================\n");
    printf("   Simple Calculator\n");
    printf("===========================\n");
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("\nSelect Operation:\n");
    printf("1. Addition       (+)\n");
    printf("2. Subtraction    (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division       (/)\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("\n--- Result ---\n");

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 4:
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed!\n");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;

        default:
            printf("Invalid choice! Please select 1 to 4.\n");
    }

    printf("==============================\n");
    printf("Thank you for using Calculator!\n");

    return 0;
}