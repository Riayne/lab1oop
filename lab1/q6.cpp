#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string studentName;
    float score1, score2, score3, score4, score5;

    // Input student's name and five test scores
    cout << "Enter the student's name: ";
    cin>>studentName;
    cout << "Enter five test scores: ";
    cin >> score1 >> score2 >> score3 >> score4 >> score5;

    // Calculate average score
    float averageScore = (score1 + score2 + score3 + score4 + score5) / 5.0;

    // Output the result
    cout << "Student name: " << studentName << endl;
    cout << "Test scores: " << fixed << setprecision(2) 
         << score1 << " " << score2 << " " << score3 << " " << score4 << " " << score5 << endl;
    cout << "Average test score: " << fixed << setprecision(2) << averageScore << endl;

    return 0;
}
