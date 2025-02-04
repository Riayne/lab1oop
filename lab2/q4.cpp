#include <iostream>
using namespace std;

struct Employees{
    int employee_id;
    string name;
    float salary;
};
struct Organisation{
    Employees emp;
    string organisation_name;
    string organisation_number;
};

int main() {
    Organisation org;

    // Assigning values to organisation data members
    org.organisation_name = "NU-Fast";
    org.organisation_number = "NUFAST123ABC";

    // Assigning values to employee data members
    org.emp.employee_id = 127;
    org.emp.name = "Linus Sebastian";
    org.emp.salary = 400000;

    // Output the structure data
    cout << "The size of structure Organisation: " << sizeof(org) << endl;
    cout << "Organisation Name: " << org.organisation_name << endl;
    cout << "Organisation Number: " << org.organisation_number << endl;
    cout << "Employee id: " << org.emp.employee_id << endl;
    cout << "Employee name: " << org.emp.name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;

    return 0;
}
