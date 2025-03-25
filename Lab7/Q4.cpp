#include <iostream>
#include <vector>

using namespace std;

// Base class: Person
class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address << "\nPhone: " << phoneNumber << "\nEmail: " << email << "\n";
    }

    virtual ~Person() {}
};

// Derived class: Student
class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double gpa;
    int enrollmentYear;

public:
    Student(string n, string i, string a, string p, string e, int year, double g)
        : Person(n, i, a, p, e), enrollmentYear(year), gpa(g) {}

    void enrollCourse(string course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << "\nGPA: " << gpa << "\nCourses Enrolled: ";
        for (const auto& course : coursesEnrolled) cout << course << ", ";
        cout << "\n";
    }
};

// Derived class: Professor
class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, string i, string a, string p, string e, string dept, double sal)
        : Person(n, i, a, p, e), department(dept), salary(sal) {}

    void addCourse(string course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (const auto& course : coursesTaught) cout << course << ", ";
        cout << "\n";
    }
};

// Derived class: Staff
class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e, string dept, string pos, double sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << "\n";
    }
};

// Course Class
class Course {
private:
    string courseID, courseName, instructor;
    int credits;
    string schedule;
    vector<Student*> students;

public:
    Course(string id, string name, string instr, int cr, string sched)
        : courseID(id), courseName(name), instructor(instr), credits(cr), schedule(sched) {}

    void registerStudent(Student* student) {
        students.push_back(student);
        student->enrollCourse(courseName);
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseID << "\nCourse Name: " << courseName << "\nInstructor: " << instructor << "\nCredits: " << credits << "\nSchedule: " << schedule << "\nStudents Enrolled: ";
        for (const auto& student : students) cout << student->id << ", ";
        cout << "\n";
    }
};

// Main function
int main() {
    Student student("Alice Johnson", "S123", "123 Main St", "555-1234", "alice@uni.edu", 2022, 3.8);
    Professor professor("Dr. Smith", "P456", "456 University Dr", "555-5678", "smith@uni.edu", "Computer Science", 85000);
    Staff staff("Jane Doe", "T789", "789 Admin Lane", "555-9876", "jane@uni.edu", "Finance", "Accountant", 50000);

    Course course("CS101", "Introduction to C++", "Dr. Smith", 4, "MWF 10:00AM");

    course.registerStudent(&student);

    cout << "=== University Members ===\n";
    student.displayInfo();
    cout << "\n";
    professor.displayInfo();
    cout << "\n";
    staff.displayInfo();
    cout << "\n";

    cout << "=== Course Info ===\n";
    course.displayCourseInfo();

    return 0;
}
