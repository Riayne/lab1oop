#include <iostream>
#include <unordered_map>

using namespace std;

// Base class: Currency
class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; // Conversion rate to base currency (e.g., USD)

public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate;
    }

    virtual double convertTo(const Currency& targetCurrency) const {
        double baseValue = convertToBase();
        return baseValue / targetCurrency.exchangeRate;
    }

    virtual void displayCurrency() const {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ") - Amount: " << amount << "\n";
    }

    virtual ~Currency() {}
};

// Derived class: Dollar
class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() const override {
        cout << "$" << amount << " (USD)\n";
    }
};

// Derived class: Euro
class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {} // Example: 1 EUR = 1.1 USD

    void displayCurrency() const override {
        cout << "€" << amount << " (EUR)\n";
    }
};

// Derived class: Rupee
class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {} // Example: 1 INR = 0.012 USD

    void displayCurrency() const override {
        cout << "₹" << amount << " (INR)\n";
    }
};

// Main function to demonstrate currency conversions
int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee inr(5000);

    cout << "=== Currency Details ===\n";
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();
    cout << "\n";

    cout << "=== Currency Conversions ===\n";
    cout << "50 EUR to USD: $" << eur.convertTo(usd) << "\n";
    cout << "100 USD to INR: ₹" << usd.convertTo(inr) << "\n";
    cout << "5000 INR to USD: $" << inr.convertTo(usd) << "\n";

    return 0;
}
