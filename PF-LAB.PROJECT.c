#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TRANSACTIONS 100

struct Transaction

{
    char type;  
    int amount;
    int balance;
};

int depmoney(int initialAmount);

int withdraw(int initialAmount);

void info(char name[], char Lname[], int cnic, int initialAmount);

int authenticatedMenu(char name[], char Lname[], int cnic, int initialAmount, struct Transaction history[], int *numTransactions);

int crtaccount(char name[], char Lname[]);

int pin();

int transfer(int initialAmount, struct Transaction history[], int *numTransactions);

void displayTransactionHistory(struct Transaction history[], int numTransactions);

void checkBalance(int initialAmount);

void changePIN();

void calculateInterest(int initialAmount);

void exit(){
printf("\t\tThis project is made by:\n");
printf("\t\tHaseeb Asif 23k-0539\n");
printf("\t\tSaad Jamil 23k-0563\n");
printf("\t\tAhsan Bari 23k-0613\n");
return(0);
}



int depmoney(int initialAmount)
{
    int depositAmount;
    printf("Enter the Amount to Deposit: ");
    
    scanf("%d", &depositAmount);

    if (depositAmount > 0) {
        initialAmount += depositAmount;
        printf("Deposit Successful. Your Updated Balance: %d\n", initialAmount);
        
    } else {
        printf("Invalid Amount for Deposit.\n");
    }

    return initialAmount;
    
}

int withdraw(int initialAmount) {
    int withdrawAmount;
    
    printf("Enter the amount to be withdrawn: ");
    scanf("%d", &withdrawAmount);
    
    if (withdrawAmount > initialAmount || withdrawAmount < 0) {
    	
        printf("You have entered an invalid amount to withdraw\n");
    } else {
        initialAmount = initialAmount - withdrawAmount;
        
        printf("The Remaining Balance is %d\n", initialAmount);
    }
    return initialAmount;
    
}

void info(char name[], char Lname[], int cnic, int initialAmount) {
	
    printf("Account Information:\n");
    
    printf("Name: %s %s\n", name, Lname);
    
    printf("CNIC: %d\n", cnic);
    
    printf("Balance: %d\n", initialAmount);
}

int authenticatedMenu(char name[], char Lname[], int cnic, int initialAmount, struct Transaction history[], int *numTransactions) {
    int choice;
    

    printf("\t\tAuthentication successful! You are now in the authenticated menu\t\t\n");
    printf("\t\t WELCOME TO ATM BANKING SYSTEM \t\t\n");
    printf("-------------------------------------------------------------------------------------------------------------\t\t\n");
    printf("\t\tPress (1) to Deposit Money\n");
    printf("\t\tPress (2) to Withdraw Money\n");
    printf("\t\tPress (3) to Show Account Information\n");
    printf("\t\tPress (4) to Transfer Money\n");
    printf("\t\tPress (5) to Display Transaction History\n");
    printf("\t\tPress (6) to Check Balance\n");
    printf("\t\tPress (7) to Change PIN\n");
    printf("\t\tPress (8) to Calculate Interest\n");
    printf("\t\tPress (9) to Exit the program\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice) 
    {
	
        case 1:
            initialAmount = depmoney(initialAmount);
            
            history[*numTransactions].type = 'D';
            
            history[*numTransactions].amount = initialAmount;
            
            history[*numTransactions].balance = initialAmount;
            
            (*numTransactions)++;
            break;
            
        case 2:
            initialAmount = withdraw(initialAmount);
            
            history[*numTransactions].type = 'W';
            
            history[*numTransactions].amount = initialAmount;
            
            history[*numTransactions].balance = initialAmount;
            
            (*numTransactions)++;
            
            break;
            
        case 3:
            info(name, Lname, cnic, initialAmount);
            
            break;
        case 4:
            initialAmount = transfer(initialAmount, history, numTransactions);
            
            break;
        case 5:
            displayTransactionHistory(history, *numTransactions);
            
            break;
        case 6:
            checkBalance(initialAmount);
            
            break;
        case 7:
            changePIN();
            
            break;
        case 8:
            calculateInterest(initialAmount);
            break;
            case 9:
            exit();
        default:
        	
            printf("Invalid Choice. Please try again.\n");
    }

    return initialAmount;
}

int crtaccount(char name[], char Lname[]) {
    int iniamount = 0, cnic;
    
    printf("\t\tTo Create your Account: Provide Following details \n ");
    printf("\n");
    printf("\t\tEnter First Name:");
    scanf("%s", name);
    printf("\n");
    printf("\t\tEnter Last Name:");
    scanf("%s", Lname);
    printf("\n");
    printf("\t\tEnter Initial Deposit Amount:");
    scanf("%d", &iniamount);
    printf("\n");
    printf("\t\tEnter your CNIC number:");
    scanf("%d", &cnic);
    return iniamount;
}

int pin() {
    char defpin[] = "data";
    char pin[5];

    printf("Enter PIN: ");
    
    for (int i = 0; i < 4; i++) {
    	
        scanf(" %c", &pin[i]);
    }
    pin[4] = '\0';

    int result = strcmp(pin, defpin);
    
    if (result == 0) {
        char name[50], Lname[50];
        
        int initialAmount = crtaccount(name, Lname);

        struct Transaction transactionHistory[MAX_TRANSACTIONS];
        
        int numTransactions = 0;

        while (1) {
            initialAmount = authenticatedMenu(name, Lname, initialAmount, initialAmount, transactionHistory, &numTransactions);
        }
    } else {
        printf("Invalid PIN\n");
        exit(0);
    }

    return 0;
}

int transfer(int initialAmount, struct Transaction history[], int *numTransactions) {
	
    int transferAmount;
    
    printf("Enter the Amount to Transfer: ");
    scanf("%d", &transferAmount);

    if (transferAmount > 0 && transferAmount <= initialAmount) {
    	
        int receiverAccount;
        printf("Enter the receiver's account number: ");
        
        scanf("%d", &receiverAccount);

        initialAmount -= transferAmount;
        

        history[*numTransactions].type = 'T';
        
        history[*numTransactions].amount = transferAmount;
        
        history[*numTransactions].balance = initialAmount;
        (*numTransactions)++;

        printf("Transfer Successful. Your Updated Balance: %d\n", initialAmount);
        
    } else {
        printf("Invalid Amount for Transfer.\n");
    }

    return initialAmount;
}

void displayTransactionHistory(struct Transaction history[], int numTransactions) {
	
    printf("\nTransaction History:\n");
    printf("Type\tAmount\tBalance\n");

    for (int i = 0; i < numTransactions; i++) {
        printf("%c\t%d\t%d\n", history[i].type, history[i].amount, history[i].balance);
        
    }
}

void checkBalance(int initialAmount) {
    printf("Your Current Balance is: %d\n", initialAmount);
    
}

void changePIN() {
    char newPIN[5];
    

    printf("Enter your new PIN: ");
    for (int i = 0; i < 4; i++) {
    	
        scanf(" %c", &newPIN[i]);
    }
    newPIN[4] = '\0';

    printf("PIN changed successfully!\n");
    
}

void calculateInterest(int initialAmount) {
	
    
    float interestRate = 0.05;

    float interest = initialAmount * interestRate;
    
    printf("Interest calculated: %.2f\n", interest);
}
int main() {
    pin();
    return 0;
    
}
