#include <stdio.h>
#include <stdlib.h>

// Structure for basic account data
struct Account {
    int acc_no;
    char name[30];
    float balance;
};

// Function declarations
void create_account();
void deposit_money();
void withdraw_money();
void balance_enquiry();

int main() {
    int choice;

    while (1) {
        printf("\n=== BANKING SYSTEM ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Balance Enquiry\n");
        printf("5. Exit\n");
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                balance_enquiry();
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

// 1. Create a new account
void create_account() {
    FILE *fp = fopen("bank.dat", "ab");
    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    struct Account a;
    printf("\nEnter Account Number: ");
    scanf("%d", &a.acc_no);

    printf("Enter Name (single word): ");
    scanf("%s", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(struct Account), 1, fp);
    fclose(fp);

    printf("\nAccount created successfully!\n");
}

// 2. Deposit money
void deposit_money() {
    FILE *fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("\nNo account file found!\n");
        return;
    }

    int target_acc, found = 0;
    int record_size = sizeof(struct Account); // Stored as a simple int
    float amount;
    struct Account a;

    printf("\nEnter Account Number: ");
    scanf("%d", &target_acc);

    while (fread(&a, sizeof(struct Account), 1, fp)) {
        if (a.acc_no == target_acc) {
            printf("Current Balance: %.2f\n", a.balance);
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            a.balance += amount;

            // Simple int offset rewind
            fseek(fp, -record_size, SEEK_CUR);
            fwrite(&a, sizeof(struct Account), 1, fp);

            printf("\nDeposit successful! New Balance: %.2f\n", a.balance);
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) {
        printf("\nAccount not found!\n");
    }
}

// 3. Withdraw money
void withdraw_money() {
    FILE *fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("\nNo account file found!\n");
        return;
    }

    int target_acc, found = 0;
    int record_size = sizeof(struct Account); // Stored as a simple int
    float amount;
    struct Account a;

    printf("\nEnter Account Number: ");
    scanf("%d", &target_acc);

    while (fread(&a, sizeof(struct Account), 1, fp)) {
        if (a.acc_no == target_acc) {
            printf("Current Balance: %.2f\n", a.balance);
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount > a.balance) {
                printf("\nError: Insufficient balance!\n");
            } else {
                a.balance -= amount;

                // Simple int offset rewind
                fseek(fp, -record_size, SEEK_CUR);
                fwrite(&a, sizeof(struct Account), 1, fp);

                printf("\nWithdrawal successful! Remaining Balance: %.2f\n", a.balance);
            }
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) {
        printf("\nAccount not found!\n");
    }
}

// 4. Check balance
void balance_enquiry() {
    FILE *fp = fopen("bank.dat", "rb");
    if (fp == NULL) {
        printf("\nNo account file found!\n");
        return;
    }

    int target_acc, found = 0;
    struct Account a;

    printf("\nEnter Account Number: ");
    scanf("%d", &target_acc);

    while (fread(&a, sizeof(struct Account), 1, fp)) {
        if (a.acc_no == target_acc) {
            printf("\n--- Account Details ---\n");
            printf("Account Number : %d\n", a.acc_no);
            printf("Name           : %s\n", a.name);
            printf("Balance        : %.2f\n", a.balance);
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) {
        printf("\nAccount not found!\n");
    }
}