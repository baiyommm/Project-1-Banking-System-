#include <iostream> // Input and Output
#include <ctime> // Time Function
#include <cstdlib> // Random Number Generator
#include <string> // Arrays and Characters
#include <iomanip> // Formatting
using namespace std;

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
