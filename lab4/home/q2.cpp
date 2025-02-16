#include <iostream>
using namespace std;

class Accounts {
    double balance;

public:
    // Constructor to initialize the balance
    Accounts(double initialBalance = 0.0) {
        if (initialBalance >= 0.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Invalid initial balance. Balance set to 0.0." << endl;
        }
    }

    // Function to credit an amount to the balance
    void credit(double amount) {
        if (amount > 0.0) {
            balance += amount;
            cout << "Credited: " << amount << endl;
        } else {
            cout << "Credit amount must be positive." << endl;
        }
    }

    // Function to debit an amount from the balance
    void debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
        } else if (amount > 0.0) {
            balance -= amount;
            cout << "Debited: " << amount << endl;
        } else {
            cout << "Debit amount must be positive." << endl;
        }
    }

    // Function to return the current balance
    double getBalance() {
        return balance;
    }
};

int main() {
    Accounts acc(100.0); // Create an account with an initial balance of 100.0

    acc.credit(50.0);  // Credit 50.0 to the account
    acc.debit(10.0);   // Debit 10.0 from the account
    acc.debit(250.0);  // Attempt to debit more than the balance

    cout << "Balance: " << acc.getBalance() << endl; // Display the current balance

    return 0;
}
