#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years_of_service;
};

// Function to write dummy data to file
void writeDummyData(const string& filename) {
    ofstream file(filename);

    file << "1,John Doe,Manager,3\n";
    file << "2,Alice Smith,Developer,1\n";
    file << "3,Bob Johnson,Manager,5\n";
    file << "4,Emily Davis,Designer,2\n";

    file.close();
}

// Function to read data from file into a vector of Employees
vector<Employee> readData(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Employee emp;
        char comma;

        ss >> emp.id >> comma;
        getline(ss, emp.name, ',');
        getline(ss, emp.designation, ',');
        ss >> emp.years_of_service;

        employees.push_back(emp);
    }

    file.close();
    return employees;
}

// Function to write data from a vector of Employees back to the file
void writeData(const string& filename, const vector<Employee>& employees) {
    ofstream file(filename, ios::trunc); // Truncate to overwrite
    for (const auto& emp : employees) {
        file << emp.id << "," << emp.name << "," << emp.designation << "," << emp.years_of_service << "\n";
    }
    file.close();
}

// Function to find employees who are Managers with at least 2 years of service
vector<Employee> findManagersWith2YearsOrMore(const vector<Employee>& employees) {
    vector<Employee> result;
    for (const auto& emp : employees) {
        if (emp.designation == "Manager" && emp.years_of_service >= 2) {
            result.push_back(emp);
        }
    }
    return result;
}

// Function to delete all data except the specified employees
void deleteExcept(vector<Employee>& employees, const vector<Employee>& keep) {
    employees.erase(remove_if(employees.begin(), employees.end(), [&](const Employee& emp) {
        return find(keep.begin(), keep.end(), emp) == keep.end();
    }), employees.end());
}

// Function to increment IDs and years of service
void incrementData(vector<Employee>& employees) {
    for (auto& emp : employees) {
        emp.id++;
        emp.years_of_service++;
    }
}

int main() {
    string filename = "employees.txt";
    
    // Write dummy data to file
    writeDummyData(filename);

    // Read data from file
    vector<Employee> employees = readData(filename);

    // Query: Find employees who are Managers with at least 2 years of service
    vector<Employee> result = findManagersWith2YearsOrMore(employees);
    cout << "Managers with at least 2 years of service:\n";
    for (const auto& emp : result) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Designation: " << emp.designation << ", Years of Service: " << emp.years_of_service << "\n";
    }

    // Delete all data except the result
    deleteExcept(employees, result);
    cout << "\nData after deletion:\n";
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Designation: " << emp.designation << ", Years of Service: " << emp.years_of_service << "\n";
    }

    // Increment IDs and years of service
    incrementData(result);
    
    // Write the updated data back to file
    employees.insert(employees.end(), result.begin(), result.end());
    writeData(filename, employees);

    // Read the updated data to verify changes
    cout << "\nData after incrementing and writing back:\n";
    employees = readData(filename);
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Designation: " << emp.designation << ", Years of Service: " << emp.years_of_service << "\n";
    }

    return 0;
}
