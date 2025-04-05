#include <iostream>
#include <limits> // For input validation

using namespace std;

// Function Prototypes
void showMenu();
double checkBalance(double balance);
void deposit(double &balance, double amount);
void withdraw(double &balance, double amount);
void exitATM();

int main() {
    const int correctPIN = 1234;
    int enteredPIN;
    int attempts = 0;
    const int maxAttempts = 3;

    // PIN entry loop
    do {
        cout << "Please enter your 4-digit PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == correctPIN) {
            cout << "PIN accepted. Access granted.\n";
            break;
        } else {
            cout << "Incorrect PIN. ";
            attempts++;
            if (attempts < maxAttempts) {
                cout << "You have " << (maxAttempts - attempts) << " attempt(s) remaining.\n";
            } else {
                cout << "Too many failed attempts. Access denied.\n";
                return 0; // Exit program
            }
        }
    } while (attempts < maxAttempts);

    double balance = 0.0;
    int choice;
    double amount;

    // ATM Menu Loop
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid choice (1-4): ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                cout << "Your current balance is: $" << checkBalance(balance) << endl;
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                while (cin.fail() || amount < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Deposit amount must be positive. Please enter a valid amount: $";
                    cin >> amount;
                }
                deposit(balance, amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                while (cin.fail() || amount < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Withdrawal amount must be positive. Please enter a valid amount: $";
                    cin >> amount;
                }
                withdraw(balance, amount);
                break;
            case 4:
                exitATM();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

void showMenu() {
    cout << "\nWelcome to the ATM\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}

double checkBalance(double balance) {
    return balance;
}

void deposit(double &balance, double amount) {
    if (amount >= 0) {
        balance += amount;
        cout << "You have successfully deposited $" << amount << ". Your new balance is $" << balance << endl;
    } else {
        cout << "Invalid deposit amount. Amount cannot be negative." << endl;
    }
}

void withdraw(double &balance, double amount) {
    if (amount < 0) {
        cout << "Invalid withdrawal amount. Amount cannot be negative." << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds. Your balance is only $" << balance << ". Withdrawal not completed." << endl;
    } else {
        balance -= amount;
        cout << "You have successfully withdrawn $" << amount << ". Your new balance is $" << balance << endl;
    }
}

void exitATM() {
    cout << "Thank you for using the ATM. Goodbye!" << endl;
}
