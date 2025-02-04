#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the inner structure
struct Subject {
    string subject_name;
};

// Define the outer structure that contains an ID and a fixed-size array of subjects
struct Student {
    int id;
    vector<Subject> subjects; // Use a vector for dynamic handling of subjects
};

// Function to print the student data
void printStudentData(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Student ID: " << student.id << endl;
        cout << "Subjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.subject_name << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;

    // Get the number of students
    cout << "Enter the number of students: ";
    cin >> N;

    vector<Student> students(N); // Create a dynamic array of students

    // Input student data
    for (int i = 0; i < N; ++i) {
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> students[i].id;

        int subjectCount;
        cout << "Enter the number of subjects for student " << i + 1 << ": ";
        cin >> subjectCount;

        // Input subjects
        for (int j = 0; j < subjectCount; ++j) {
            string subject;
            cout << "Enter subject " << j + 1 << ": ";
            cin >> subject;
            students[i].subjects.push_back({subject});
        }
    }

    // Print all student data
    cout << "\nStudent Data:" << endl;
    printStudentData(students);

    return 0;
}

