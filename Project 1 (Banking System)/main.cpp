#include <iostream> // Input and Output
#include <ctime> // Time Function
#include <cstdlib> // Random Number Generator
#include <string> // Arrays and Characters
#include <iomanip> // Formatting
using namespace std;

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
