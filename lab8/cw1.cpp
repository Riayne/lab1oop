#include <iostream>
#include <string>
#include <stdexcept>

class Wallet {
private:
    double balance;
    double dailyDeposited;
    double dailyWithdrawn;
    
    const double MAX_DAILY_DEPOSIT = 10000.0;
    const double MAX_DAILY_WITHDRAWAL = 5000.0;
    
    // Simple date tracking using a counter (for demonstration)
    static int currentDay;
    
    int lastResetDay;
    
    void checkResetDailyLimits() {
        if (currentDay != lastResetDay) {
            dailyDeposited = 0.0;
            dailyWithdrawn = 0.0;
            lastResetDay = currentDay;
        }
    }
    
public:
    Wallet() : balance(0.0), dailyDeposited(0.0), dailyWithdrawn(0.0), lastResetDay(currentDay) {}
    
    bool deposit(double amount) {
        checkResetDailyLimits();
        
        if (amount <= 0) {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        
        if (dailyDeposited + amount > MAX_DAILY_DEPOSIT) {
            double remaining = MAX_DAILY_DEPOSIT - dailyDeposited;
            throw std::runtime_error("Exceeds daily deposit limit. You can deposit up to $" + 
                                    std::to_string(remaining) + " more today.");
        }
        
        balance += amount;
        dailyDeposited += amount;
        return true;
    }
    
    bool withdraw(double amount) {
        checkResetDailyLimits();
        
        if (amount <= 0) {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        
        if (amount > balance) {
            throw std::runtime_error("Insufficient funds");
        }
        
        if (dailyWithdrawn + amount > MAX_DAILY_WITHDRAWAL) {
            double remaining = MAX_DAILY_WITHDRAWAL - dailyWithdrawn;
            throw std::runtime_error("Exceeds daily withdrawal limit. You can withdraw up to $" + 
                                   std::to_string(remaining) + " more today.");
        }
        
        balance -= amount;
        dailyWithdrawn += amount;
        return true;
    }
    
    double getBalance() const {
        return balance;
    }
    
    // Static method to simulate day change (for testing)
    static void advanceDay() {
        currentDay++;
    }
};

// Initialize static member
int Wallet::currentDay = 1;

class User {
private:
    std::string userId;
    std::string name;
    Wallet wallet;
    
public:
    User(const std::string& id, const std::string& userName) 
        : userId(id), name(userName) {}
    
    void deposit(double amount) {
        wallet.deposit(amount);
    }
    
    void withdraw(double amount) {
        wallet.withdraw(amount);
    }
    
    double getBalance() const {
        return wallet.getBalance();
    }
    
    void printInfo() const {
        std::cout << "User ID: " << userId 
                  << "\nName: " << name 
                  << "\nBalance: $" << getBalance() 
                  << std::endl;
    }
};

int main() {
    // Create users
    User alice("U1001", "Alice Johnson");
    User bob("U1002", "Bob Smith");
    
    // Demonstrate deposits
    try {
        alice.deposit(500);
        std::cout << "Alice deposited $500. New balance: $" << alice.getBalance() << std::endl;
        
        alice.deposit(9500);
        std::cout << "Alice deposited $9500. New balance: $" << alice.getBalance() << std::endl;
        
        // This should fail (exceeds daily limit)
        alice.deposit(100);
    } catch (const std::exception& e) {
        std::cout << "Alice deposit error: " << e.what() << std::endl;
    }
    
    // Demonstrate withdrawals
    try {
        alice.withdraw(200);
        std::cout << "Alice withdrew $200. New balance: $" << alice.getBalance() << std::endl;
        
        // This should fail (insufficient funds)
        alice.withdraw(10000);
    } catch (const std::exception& e) {
        std::cout << "Alice withdrawal error: " << e.what() << std::endl;
    }
    
    // Bob's transactions
    try {
        bob.deposit(1500);
        std::cout << "Bob deposited $1500. New balance: $" << bob.getBalance() << std::endl;
        
        bob.withdraw(600);
        std::cout << "Bob withdrew $600. New balance: $" << bob.getBalance() << std::endl;
        
        // This should fail (exceeds daily withdrawal limit)
        bob.withdraw(4500);
    } catch (const std::exception& e) {
        std::cout << "Bob withdrawal error: " << e.what() << std::endl;
    }
    
    // Demonstrate day change
    std::cout << "\nAdvancing to the next day..." << std::endl;
    Wallet::advanceDay();
    
    try {
        // Now Alice can deposit again (daily limit reset)
        alice.deposit(100);
        std::cout << "Alice deposited $100 (new day). New balance: $" << alice.getBalance() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Alice deposit error: " << e.what() << std::endl;
    }
    
    // Show final balances
    std::cout << "\nFinal balances:" << std::endl;
    std::cout << "Alice: $" << alice.getBalance() << std::endl;
    std::cout << "Bob: $" << bob.getBalance() << std::endl;
    
    return 0;
}
