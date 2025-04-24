#include <iostream>
#include <string>
using namespace std;

// Abstract class Student
class Student {
protected:
    string name;
    int creditHours;

public:
    Student(string n, int c) : name(n), creditHours(c) {}
    virtual double getTuition(string status) = 0; // Pure virtual function

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }
};

// Derived class GraduateStudent
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int c, string topic) : Student(n, c), researchTopic(topic) {}

    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    double getTuition(string status) override {
        if (status == "Undergraduate") {
            return creditHours * 200;
        } else if (status == "Graduate") {
            return creditHours * 300;
        } else if (status == "Doctoral") {
            return creditHours * 400;
        }
        return 0.0;
    }
};

int main() {
    GraduateStudent gradStudent("Alice", 12, "Quantum Computing");

    cout << "Student Name: " << gradStudent.getName() << endl;
    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;
    cout << "Tuition for Graduate student: $" << gradStudent.getTuition("Graduate") << endl;

    return 0;
}
