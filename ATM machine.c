#include <stdio.h>

#define INITIAL_BALANCE 1000.0

typedef enum {
    VIEW_BALANCE = 1,
    DEPOSIT_MONEY,
    WITHDRAW_MONEY,
    EXIT
} MenuOption;

void viewBalance(float balance);
void depositMoney(float *balance);
void withdrawMoney(float *balance);

int main() {
    MenuOption choice;
    float balance = INITIAL_BALANCE;

    while(1) {
        printf("\n=== ATM MENU ===\n");
        printf("1. View Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
            // clear invalid input
            while(getchar() != '\n');
            continue;
        }
        
        printf("\n");

        switch(choice) {
            case VIEW_BALANCE:
                viewBalance(balance);
                break;
            case DEPOSIT_MONEY:
                depositMoney(&balance);
                break;
            case WITHDRAW_MONEY:
                withdrawMoney(&balance);
                break;
            case EXIT:
                printf("Thank you! Visit Again.\n");
                return 0;
            default:
                printf("Invalid Choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

void viewBalance(float balance) {
    printf("Your Balance: ₹%.2f\n", balance);
}

void depositMoney(float *balance) {
    float amount;
    
    printf("Enter amount to deposit: ₹");
    
    if (scanf("%f", &amount) == 1 && amount > 0) {
        *balance += amount;
        printf("Deposit Successful! New Balance: ₹%.2f\n", *balance);
    } else {
        printf("Invalid amount entered. Please try again.\n");
        while(getchar() != '\n');
    }
}

void withdrawMoney(float *balance) {
    float amount;
    
    printf("Enter amount to withdraw: ₹");
    
    if (scanf("%f", &amount) == 1 && amount > 0) {
        if (amount <= *balance) {
            *balance -= amount;
            printf("Withdrawal Successful! New Balance: ₹%.2f\n", *balance);
        } else
            printf("Insufficient Balance!\n");
    } else {
        printf("Invalid amount entered. Please try again.\n");
        while(getchar() != '\n');
    }
}
