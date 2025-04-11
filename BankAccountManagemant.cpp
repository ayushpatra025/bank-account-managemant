#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account details
typedef struct {
    long long accountNumber;
    char name[50];
    float balance;
} Account;

// Function prototypes
void depositMoney(Account *acc);
void withdrawMoney(Account *acc);
void displayAccountDetails(Account *acc);
void transferMoney(Account *acc1, Account *acc2);
void checkBalance(Account *acc);

int main() {
    Account acc1, acc2;
    int choice;
    
    // Take account details first
    do {
        printf("\nEnter Account Number: ");
        scanf("%lld", &acc1.accountNumber);
        if (acc1.accountNumber < 1000000000LL || acc1.accountNumber > 9999999999999LL) {
            printf("Invalid account number!\n");
        }
    } while (acc1.accountNumber < 1000000000LL || acc1.accountNumber > 9999999999999LL);
    
    printf("Enter Account Holder Name: ");
    scanf("%s", acc1.name);
    acc1.balance = 0.0; // Initial balance set to zero

    while (1) {
        printf("\n=== Bank Account Management System ===\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Display Account Details\n");
        printf("4. Transfer Money\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                depositMoney(&acc1);
                break;
            case 2:
                withdrawMoney(&acc1);
                break;
            case 3:
                displayAccountDetails(&acc1);
                break;
            case 4:
                do {
                    printf("\nEnter Second Account Number: ");
                    scanf("%lld", &acc2.accountNumber);
                    if (acc2.accountNumber < 1000000000LL || acc2.accountNumber > 9999999999999LL) {
                        printf("Invalid account number!\n");
                    }
                } while (acc2.accountNumber < 1000000000LL || acc2.accountNumber > 9999999999999LL);
                
                printf("Enter Second Account Holder Name: ");
                scanf("%s", acc2.name);
                acc2.balance = 0.0;
                transferMoney(&acc1, &acc2);
                break;
            case 5:
                checkBalance(&acc1);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void depositMoney(Account *acc) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("Amount deposited successfully! New Balance: %.2f\n", acc->balance);
    } else {
        printf("Invalid amount. Please enter a positive value.\n");
    }
}

void withdrawMoney(Account *acc) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Amount withdrawn successfully! Remaining Balance: %.2f\n", acc->balance);
    } else {
        printf("Insufficient balance or invalid amount.\n");
    }
}

void displayAccountDetails(Account *acc) {
    printf("\n=== Account Details ===\n");
    printf("Account Number: %lld\n", acc->accountNumber);
    printf("Account Holder: %s\n", acc->name);
    printf("Current Balance: %.2f\n", acc->balance);
}

void transferMoney(Account *acc1, Account *acc2) {
    float amount;
    printf("\nEnter amount to transfer: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc1->balance) {
        acc1->balance -= amount;
        acc2->balance += amount;
        printf("Transfer successful!\n");
        printf("%s's new balance: %.2f\n", acc1->name, acc1->balance);
        printf("%s's new balance: %.2f\n", acc2->name, acc2->balance);
    } else {
        printf("Insufficient balance or invalid amount.\n");
    }
}

void checkBalance(Account *acc) {
    printf("\nCurrent Balance: %.2f\n", acc->balance);
}

