#include <iostream>
using namespace std;

class StudentFeeManager {
private:
    int* fees;
    int size;
public:
    StudentFeeManager(int numStudents, int initialFee) : size(numStudents) {
        fees = new int[size];
        for (int i = 0; i < size; ++i)
            fees[i] = initialFee;
    }

    StudentFeeManager(const StudentFeeManager& other) : size(other.size) {
        fees = new int[size];
        for (int i = 0; i < size; ++i)
            fees[i] = other.fees[i];
    }

    StudentFeeManager& operator=(const StudentFeeManager& other) {
        if (this != &other) {
            delete[] fees;
            size = other.size;
            fees = new int[size];
            for (int i = 0; i < size; ++i)
                fees[i] = other.fees[i];
        }
        return *this;
    }

    ~StudentFeeManager() {
        delete[] fees;
    }

    void setFee(int index, int fee) { // assuming index is valid
        fees[index] = fee;
    }

    void printFees() const {
        for (int i = 0; i < size; ++i)
            cout << "Student " << i + 1 << " fee: " << fees[i] << endl;
    }
};

int main() {
    StudentFeeManager manager(3, 1000);

    cout << "Original manager fees:" << endl;
    manager.printFees();

    StudentFeeManager copiedManager = manager;

    copiedManager.setFee(1, 2000);

    cout << "\nAfter modifying copied manager:" << endl;
    cout << "Original manager fees:" << endl;
    manager.printFees();

    cout << "Copied manager fees:" << endl;
    copiedManager.printFees();

    return 0;
}
