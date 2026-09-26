#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void printMenu();
void clearInputBuffer();
void calculate(int choice);

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice (1-5): ");
        
        // Input validation: ensure user enters an integer
        if (scanf("%d", &choice) != 1) {
            printf("\n[Error] Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }

        // Exit condition
        if (choice == 5) {
            printf("\nExiting program. Goodbye!\n");
            break;
        }

        // Validate menu selection range
        if (choice >= 1 && choice <= 4) {
            calculate(choice);
        } else {
            printf("\n[Error] Invalid selection. Choose an option between 1 and 5.\n");
        }

        printf("\n----------------------------------------\n");
    }

    return 0;
}

// Display Program Menu
void printMenu() {
    printf("\n========================================\n");
    printf("         BASIC C CALCULATOR             \n");
    printf("========================================\n");
    printf(" 1. Addition (+)\n");
    printf(" 2. Subtraction (-)\n");
    printf(" 3. Multiplication (*)\n");
    printf(" 4. Division (/)\n");
    printf(" 5. Exit Program\n");
    printf("========================================\n");
}

// Clears the input buffer to prevent infinite loops on invalid input
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Handles input reading and arithmetic calculations
void calculate(int choice) {
    double num1, num2, result;

    printf("Enter two numbers: ");
    
    // Validate numerical input
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("\n[Error] Invalid input. Please enter numerical values.\n");
        clearInputBuffer();
        return;
    }

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("\nResult: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("\nResult: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("\nResult: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;

        case 4:
            // Edge-case check: Division by zero
            if (num2 == 0) {
                printf("\n[Error] Division by zero is undefined.\n");
            } else {
                result = num1 / num2;
                printf("\nResult: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
    }
}