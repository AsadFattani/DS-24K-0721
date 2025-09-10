#include <iostream>
#include <string>
using namespace std;

int main() {
    int students = 5;
    string *studentIDs = new string[students];
    int *courseCounts = new int[students];
    int **marks = new int*[students];

    for (int i = 0; i < students; ++i) {
        cout << "Enter Student " << i + 1 << " ID: ";
        cin >> studentIDs[i];
        cout << "Enter number of courses for Student " << studentIDs[i] << ": ";
        cin >> courseCounts[i];

        marks[i] = new int[courseCounts[i]];
        for (int j = 0; j < courseCounts[i]; ++j) {
            cout << "Enter mark for course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    cout << "\nStudent Marks:\n";
    for (int i = 0; i < students; ++i) {
        cout << "Student ID: " << studentIDs[i] << "\nCourses: " << courseCounts[i] << "\nMarks: ";
        for (int j = 0; j < courseCounts[i]; ++j) {
            cout << marks[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < students; ++i) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] studentIDs;
    delete[] courseCounts;

    return 0;
}
