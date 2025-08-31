#include <iostream>
using namespace std;

class Box {
private:
    int* data;
public:
    Box(int value = 0) {
        data = new int(value);
    }

    ~Box() {
        delete data;
    }

    Box(const Box& other) {
        data = new int(*other.data);
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    void shallowCopy(const Box& other) {
        delete data;
        data = other.data; 
    }

    void setValue(int value) {
        *data = value;
    }

    int getValue() const {
        return *data;
    }
};

int main() {
    cout << "Demonstrating Deep Copy:" << endl;
    Box b1(10);
    Box b2 = b1; 
    b2.setValue(20);
    cout << "b1 value: " << b1.getValue() << endl; 
    cout << "b2 value: " << b2.getValue() << endl; 

    Box b3;
    b3 = b1;
    b3.setValue(30);
    cout << "b1 value: " << b1.getValue() << endl; 
    cout << "b3 value: " << b3.getValue() << endl; 

    cout << "\nDemonstrating Shallow Copy:" << endl;
    Box b4(40);
    Box b5;
    b5.shallowCopy(b4);
    b5.setValue(50);
    cout << "b4 value: " << b4.getValue() << endl;
    cout << "b5 value: " << b5.getValue() << endl;


    return 0;
}
