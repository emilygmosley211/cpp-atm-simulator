#include <iostream>
#include <limits> // For input validation

using namespace std;

// Function Prototypes
void showMenu();
double checkBalance(double balance); // Pass-by-value because it only returns the balance
void deposit(double &balance, double amount); // Pass-by-reference to modify the balance
void withdraw(double &balance, double amount); // Pass-by-reference to modify the balance
void exitATM();

int main() {
    double balance = 0.0; // Initial balance set to 0
    int choice;
    double amount;

    // ATM Menu Loop
    do {
        showMenu();  // Display menu options
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation for the menu choice
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice (1-4): ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                // Check balance
                cout << "Your current balance is: $" << checkBalance(balance) << endl;
                break;
            case 2:
                // Deposit money
                cout << "Enter amount to deposit: $";
                cin >> amount;
                // Input validation for deposit amount
                while (cin.fail() || amount < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Deposit amount must be positive. Please enter a valid amount: $";
                    cin >> amount;
                }
                deposit(balance, amount); // Call deposit (pass-by-reference)
                break;
            case 3:
                // Withdraw money
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                // Input validation for withdrawal amount
                while (cin.fail() || amount < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Withdrawal amount must be positive. Please enter a valid amount: $";
                    cin >> amount;
                }
                withdraw(balance, amount); // Call withdraw (pass-by-reference)
                break;
            case 4:
                // Exit program
                exitATM();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0;
}

// Function to display the ATM menu
void showMenu() {
    cout << "\nWelcome to the ATM\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}

// Function to check the balance (returns the current balance, pass-by-value)
double checkBalance(double balance) {
    return balance; // Simply returns the balance without modifying it
}

// Function to deposit money (pass-by-reference to modify balance)
void deposit(double &balance, double amount) {
    if (amount >= 0) {
        balance += amount;  // Modify the balance directly using pass-by-reference
        cout << "You have successfully deposited $" << amount << ". Your new balance is $" << balance << endl;
    } else {
        cout << "Invalid deposit amount. Amount cannot be negative." << endl;
    }
}

// Function to withdraw money (pass-by-reference to modify balance)
void withdraw(double &balance, double amount) {
    if (amount < 0) {
        cout << "Invalid withdrawal amount. Amount cannot be negative." << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds. Your balance is only $" << balance << ". Withdrawal not completed." << endl;
    } else {
        balance -= amount;  // Modify the balance directly using pass-by-reference
        cout << "You have successfully withdrawn $" << amount << ". Your new balance is $" << balance << endl;
    }
}

// Function to exit the ATM (goodbye message)
void exitATM() {
    cout << "Thank you for using the ATM. Goodbye!" << endl;
}
