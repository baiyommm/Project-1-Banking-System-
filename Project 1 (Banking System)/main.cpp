#include <iostream> // Input and Output
#include <ctime> // Time Function
#include <cstdlib> // Random Number Generator
#include <string> // Arrays and Characters
#include <iomanip> // Formatting
using namespace std;

// Function Header to print out the deposits
void deposit(double &balance, double amount);

// Function Header for various Bank Accounts: Checking vs Savings vs Business
void handleAccount(int accountType, double &balance);

int main() {

    // code for random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    time_t now = time(0); // function to get the current system time (time is in seconds)
    char* dt = ctime(&now); // converts the time to a string (readable format) stores the time(0) data into dt
    
    int accountType;
    double balance;
    
    cout << "Select Account Type: \n1. Checking Account \n2. Savings Account \n3. Business Account" << endl;
    cin >> accountType;
    
    cout << "Enter Initial Balance: ";
    cin >> balance;
    
    return 0;
}

// Function to print out the deposits and log the deposit transaction.
void deposit(double &balance, double amount) {
    if (amount > 0) {
        balance += amount; // adds the amount to the balance
   //     logTransaction("Deposit", amount); // for future reference: logTransaction function to print log
        cout << "You Deposited: $" << amount << ".\n The New Balance Is: $" << balance << "." << endl;
        // Random confirmation number (uses 1000000 to ensure random number doesn't go beyond 1 million)
        cout << "Confirmation Number: " << rand() % 1000000 + 1 << endl; // uses +1 to ensure that result isn't 0
    }
    else {
        cout << "Invalid Deposit Amount." << endl;
    }
}

    // Function for various Bank Accounts: Checking vs Savings vs Business
void handleAccount(int accountType, double &balance) {
    double amount;
    double withdrawalFee;
    double interestRate;
    double minBalance;
    
    // Switch function to handle account types
    switch(accountType) {
        case 1: // Checking Account
            withdrawalFee = 1.00;
            interestRate = 0.01;
            minBalance = 0.0; // No minimum balance requirement
            break;
        case 2: // Savings Account
            withdrawalFee = 2.00;
            interestRate = 0.02;
            minBalance = 1000.00; // Minimum balance requirement
            break;
        case 3: // Business Account
            withdrawalFee = 5.00;
            interestRate = 0.05;
            minBalance = 10000.00; // Minimum balance requirement
            break;
        default:
            cout << "Invalid Account Type. Please Re-enter The Correct Account." << endl;
            return;
    }
}
