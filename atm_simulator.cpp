#include <iostream>
#include <limits> // For input validation

using namespace std;

int main() {
    double balance = 0.0; // Initial balance set to 0
    int choice;
    double amount;
    
    // ATM Menu Loop...
}
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
        case 1: // Check balance
            break;
        case 2: // Deposit money
            break;
        case 3: // Withdraw money
            break;
        case 4: // Exit
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
} while (choice != 4); // Continue until the user chooses to exit
void showMenu() {
    cout << "\nWelcome to the ATM\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}
