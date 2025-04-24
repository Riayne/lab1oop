#include <iostream>
#include <string>
using namespace std;

// Abstract class Car
class Car {
protected:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}
    virtual void setPrice(double p) = 0; // Pure virtual function
    string getModel() { return model; }
    double getPrice() { return price; }
};

// Derived class Color
class Color : public Car {
public:
    Color(string m, double p) : Car(m, p) {}

    void setPrice(double p) override {
        price = p;
    }
};

// Derived class Company
class Company : public Car {
public:
    Company(string m, double p) : Car(m, p) {}

    void setPrice(double p) override {
        price = p;
    }
};

int main() {
    Color carColor("Red Sedan", 25000);
    Company carCompany("Tesla Model S", 70000);

    cout << "Model: " << carColor.getModel() << ", Price: " << carColor.getPrice() << endl;
    carColor.setPrice(26000);  // Update price
    cout << "Updated Model: " << carColor.getModel() << ", Price: " << carColor.getPrice() << endl;

    cout << "Model: " << carCompany.getModel() << ", Price: " << carCompany.getPrice() << endl;
    carCompany.setPrice(75000);  // Update price
    cout << "Updated Model: " << carCompany.getModel() << ", Price: " << carCompany.getPrice() << endl;

    return 0;
}
