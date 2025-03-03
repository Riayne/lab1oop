#include <iostream>
using namespace std;

class Student {
public:
    const int rollNo;

    Student() : rollNo(0) {}

    void setRollNo(int roll) {
        const_cast<int&>(rollNo) = roll;
    }

    void display() {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main() {
    Student student;
    int roll;
    cout << "Enter student roll number: ";
    cin >> roll;
    student.setRollNo(roll);
    student.display();

    return 0;
}
