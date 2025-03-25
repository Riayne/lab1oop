#include <iostream>
#include <vector>

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(string accNum, string holderName, double initialBalance, string type = "General")
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance), accountType(type) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << ".\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << ".\n";
            return true;
        } else {
            cout << "Withdrawal failed. Insufficient funds or invalid amount.\n";
            return false;
        }
    }

    virtual double calculateInterest() const {
        return 0.0;
    }

    virtual void printStatement() const {
        cout << "Account Statement:\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolderName << "\n";
        cout << "Balance: $" << balance << "\n";
    }

    virtual void getAccountInfo() const {
        cout << "Account Info:\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Holder Name: " << accountHolderName << "\n";
        cout << "Balance: $" << balance << "\n";
        cout << "Account Type: " << accountType << "\n";
    }

    virtual ~Account() {}
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNum, string holderName, double initialBalance, double rate, double minBal)
        : Account(accNum, holderName, initialBalance, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() const override {
        return (balance >= minimumBalance) ? balance * (interestRate / 100) : 0.0;
    }

    bool withdraw(double amount) override {
        if ((balance - amount) >= minimumBalance) {
            return Account::withdraw(amount);
        } else {
            cout << "Withdrawal failed. Maintaining minimum balance of $" << minimumBalance << " is required.\n";
            return false;
        }
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

// Derived class: CheckingAccount
class CheckingAccount : public Account {
public:
    CheckingAccount(string accNum, string holderName, double initialBalance)
        : Account(accNum, holderName, initialBalance, "Checking") {}

    void printStatement() const override {
        Account::printStatement();
        cout << "Checking accounts do not earn interest.\n";
    }
};

// Derived class: FixedDepositAccount
class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(string accNum, string holderName, double initialBalance, double rate, string maturity)
        : Account(accNum, holderName, initialBalance, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() const override {
        return balance * (fixedInterestRate / 100);
    }

    bool withdraw(double amount) override {
        cout << "Withdrawals are not allowed before maturity date: " << maturityDate << ".\n";
        return false;
    }

    void printStatement() const override {
        Account::printStatement();
        cout << "Fixed Deposit Interest Rate: " << fixedInterestRate << "%\n";
        cout << "Maturity Date: " << maturityDate << "\n";
    }
};

// Main function to demonstrate the banking system
int main() {
    SavingsAccount savings("S123", "John Doe", 5000.0, 2.5, 1000.0);
    CheckingAccount checking("C456", "Jane Smith", 2000.0);
    FixedDepositAccount fixed("F789", "Alice Brown", 10000.0, 5.0, "2026-12-31");

    cout << "=== Account Details ===\n";
    savings.getAccountInfo();
    cout << "\n";
    checking.getAccountInfo();
    cout << "\n";
    fixed.getAccountInfo();
    cout << "\n";

    cout << "=== Transactions ===\n";
    savings.deposit(1000);
    savings.withdraw(4500);
    cout << "Interest Earned: $" << savings.calculateInterest() << "\n\n";

    checking.deposit(500);
    checking.withdraw(1000);
    checking.printStatement();
    cout << "\n";

    fixed.deposit(2000);
    fixed.withdraw(5000);
    cout << "Interest Earned: $" << fixed.calculateInterest() << "\n\n";

    return 0;
}
