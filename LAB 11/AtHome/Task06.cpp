#include <iostream>
using namespace std;

#define SIZE 15

class StudentRecord {
    public:
    int rollNo;
    string name;
    bool isOccupied;
    StudentRecord() : rollNo(-1), name(""), isOccupied(false) {}
};

class StudentHashTable {
    StudentRecord table[SIZE];
    public:
        StudentHashTable() {}

        int hashFunction(int key) {
            return key % SIZE;
        }

        void insert(int rollNo, string name) {
            int index = hashFunction(rollNo);
            int attempt = 0;
            while (attempt < SIZE) {
                int probeIndex = (index + attempt * attempt) % SIZE;
                if (!table[probeIndex].isOccupied) {
                    table[probeIndex].rollNo = rollNo;
                    table[probeIndex].name = name;
                    table[probeIndex].isOccupied = true;
                    cout << "Inserting " << rollNo << " at index " << probeIndex << endl;
                    return;
                }
                attempt++;
            } 
            cout << "Hash table is full, cannot insert " << rollNo << endl;
        }
        
        void Search(int rollNo) {
            int index = hashFunction(rollNo);
            int attempt = 0;
            while (attempt < SIZE) {
                int probeIndex = (index + attempt * attempt) % SIZE;
                if (table[probeIndex].isOccupied && table[probeIndex].rollNo == rollNo) {
                    cout << "Student found: " << table[probeIndex].name << endl;
                    return;
                } 
                if (!table[probeIndex].isOccupied){
                    break;
                }
                attempt++;
            } 
            cout << "Record not found" << endl;
        }
};


int main() {
    StudentHashTable sht;
    sht.insert(101, "Omer");
    sht.insert(116, "Ali");
    sht.insert(131, "Ahmed");
    sht.insert(146, "Sara");

    sht.Search(131);
    sht.Search(200);
    
    return 0;
}