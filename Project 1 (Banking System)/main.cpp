#include <iostream> // Input and Output
#include <ctime> // Time Function
#include <cstdlib> // Random Number Generator
#include <string> // Arrays and Characters
#include <iomanip> // Formatting
using namespace std;

// Global Arrays to store transaction details (History Log)
const int max_transactions = 100; // Max number of transactions that can be logged (const int)
string transactionType[max_transactions];
double transactionAmount[max_transactions];
string transactionDate[max_transactions];
int transactionCount = 0; // starts at 0

// [Prototype] Function Declaration to the Log Transaction
void logTransaction(string type, double amount);

// [Prototype] Function Declaration for printing the Transaction History Log
void printTransactionHistory();
    
// [Prototype] Function Declaration to print out the deposits
void deposit(double &balance, double amount);

// [Prototype] Function Declaration (Boolean) to handle withdrawals along with fees depending on the account type
bool withdraw(double &balance, double amount, double fee);

// [Prototype] Function Declaration for various Bank Accounts: Checking vs Savings vs Business
void handleAccount(int accountType, double &balance);

// Function to calculate interest (formula)
double calculateInterest(double balance, double interestRate) {
    return balance * interestRate;
}

int main() {

    // code for random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    int accountType;
    double balance;
    
    cout << "Select Account Type: \n1. Checking Account \n2. Savings Account \n3. Business Account" << endl;
    cin >> accountType;
    
    cout << "Enter Initial Balance: ";
    cin >> balance;
    
    return 0;
}

// Function to log transactions
void logTransaction(string type, double amount) {
    if (transactionCount < max_transactions) {
        time_t now = time(0); // function to get the current system time (time is in seconds)
        char* dt = ctime(&now); // converts time to a string (readable format), stores the time(0) data into dt
        transactionType[transactionCount] = type;
        transactionAmount[transactionCount] = amount;
        transactionDate[transactionCount] = dt;
        transactionCount++;
    } 
    else {
        cout << "Transaction log is full!\n";
    }
}

// Function to print transaction history
void printTransactionHistory() {
    cout << "Transaction History: " << endl;
    for (int i = 0; i < transactionCount; i++) {
        cout << "Type: " << transactionType[i]
             << ", Amount: $" << fixed << setprecision(2) << transactionAmount[i] // dollar amount (2 decimals)
             << ", Date: " << transactionDate[i];
    }
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

// Function to handle withdrawals with fees associated with the account type
bool withdraw(double &balance, double amount, double fee) {
    if (amount > 0 && amount + fee <= balance) {
        balance -= (amount + fee);
 //       logTransaction("Withdrawal", amount); // for future reference: logTransaction function to print log
        cout << "You Withdrew $" << amount << " with fee $" << fee << ".\n The New balance Is: $" << balance << "." << endl;
        return true;
    } 
    else {
        cout << "Invalid or Insufficient Funds." << endl;
        return false;
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
