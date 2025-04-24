#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void getData() = 0;   // Pure virtual function
    virtual void displayData() = 0; 
    virtual void bonus() = 0;  // Pure virtual function for bonus
};

// Derived class Admin
class Admin : public Person {
protected:
    string department;

public:
    Admin(string n, int a, string d) : Person(n, a), department(d) {}
    void getData() override {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Department: ";
        cin >> department;
    }
    
    void displayData() override {
        cout << "Admin Name: " << name << ", Age: " << age << ", Department: " << department << endl;
    }

    void bonus() override {
        cout << "Admin Bonus: $5000" << endl;
    }
};

// Derived class Account
class Account : public Person {
protected:
    double salary;

public:
    Account(string n, int a, double s) : Person(n, a), salary(s) {}
    void getData() override {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayData() override {
        cout << "Account Name: " << name << ", Age: " << age << ", Salary: " << salary << endl;
    }

    void bonus() override {
        cout << "Account Bonus: $4000" << endl;
    }
};

int main() {
    Admin admin("John", 40, "HR");
    Account account("Alice", 30, 55000);

    Person* person1 = &admin;
    Person* person2 = &account;

    person1->getData();
    person1->displayData();
    person1->bonus();

    person2->getData();
    person2->displayData();
    person2->bonus();

    return 0;
}
