#include <iostream>
#include <string>
using namespace std;

int main() {
    string departments[] = {"SE", "AI", "CS", "DS"};
    int numCourses[] = {3, 4, 2, 1};
    int deptCount = 4;

    double* gpas[deptCount];  

    for (int i = 0; i < deptCount; i++) {
        gpas[i] = new double[numCourses[i]];
    }

    for (int i = 0; i < deptCount; i++) {
        cout << "Enter GPAs for " << departments[i] 
             << " (" << numCourses[i] << " courses):\n";
        for (int j = 0; j < numCourses[i]; j++) {
            cout << "  Enter GPA for course " << j + 1 
                 << " in " << departments[i] << ": ";
            cin >> gpas[i][j];
        }
    }

    cout << "\n--- GPA Report ---\n";
    for (int i = 0; i < deptCount; i++) {
        cout << "Department: " << departments[i] << endl;
        cout << "Courses GPAs:\n";
        for (int j = 0; j < numCourses[i]; j++) {
            cout << "  Course " << j + 1 << ": " << gpas[i][j] << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < deptCount; i++) {
        delete[] gpas[i];
    }

    return 0;
}
