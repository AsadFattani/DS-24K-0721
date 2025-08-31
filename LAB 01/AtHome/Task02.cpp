#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string studentName;
    string examDate;
    float score;

public:
    Exam() : studentName(""), examDate(""), score(0.0f) {}

    void setStudentName(const string& name) {
        studentName = name;
    }

    void setExamDate(const string& date) {
        examDate = date;
    }

    void setScore(float s) {
        score = s;
    }

    void display() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " <<  examDate << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam exam1;
    exam1.setStudentName("Ali");
    exam1.setExamDate("2024-07-21");
    exam1.setScore(95.5f);

    cout << "Original Exam:\n";
    exam1.display();

    Exam exam2 = exam1;
    cout << "\nShallow Copied Exam:\n";
    exam2.display();

    exam2.setStudentName("omer");
    exam1.setStudentName("amjad");

    cout << "\n--- After Modifying Copied Exam ---\n";
    cout << "Original Exam:\n";
    exam1.display();
    cout << "\nModified Copied Exam:\n";
    exam2.display();

    return 0;
}
