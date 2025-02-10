#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    // Constructor
    Employee(string firstName, string lastName, double monthlySalary) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->monthlySalary = (monthlySalary > 0) ? monthlySalary : 0.0;
    }

    // Getter methods
    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    double getMonthlySalary() {
        return monthlySalary;
    }

    // Setter methods
    void setFirstName(string firstName) {
        this->firstName = firstName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    void setMonthlySalary(double monthlySalary) {
        if (monthlySalary > 0) {
            this->monthlySalary = monthlySalary;
        } else {
            this->monthlySalary = 0.0;
        }
    }

    // Method to return yearly salary
    double getYearlySalary() {
        return monthlySalary * 12;
    }

    // Method to give a 10% raise
    void giveRaise() {
        this->monthlySalary *= 1.10;
    }
};

int main() {
    // Creating two Employee objects
    Employee emp1("John", "Doe", 3000.00);
    Employee emp2("Jane", "Smith", 4000.00);

    // Displaying initial yearly salaries
    cout << emp1.getFirstName() << " " << emp1.getLastName() << " Yearly Salary: " << emp1.getYearlySalary() << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName() << " Yearly Salary: " << emp2.getYearlySalary() << endl;

    // Giving each employee a 10% raise
    emp1.giveRaise();
    emp2.giveRaise();

    // Displaying new yearly salaries after the raise
    cout << "After 10% raise:" << endl;
    cout << emp1.getFirstName() << " " << emp1.getLastName() << " Yearly Salary: " << emp1.getYearlySalary() << endl;
    cout << emp2.getFirstName() << " " << emp2.getLastName() << " Yearly Salary: " << emp2.getYearlySalary() << endl;

    return 0;
}
