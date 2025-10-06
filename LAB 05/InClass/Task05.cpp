#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n < 10) {
        return (n % 10 == 0) ? 0 : n;
    }
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sumOfDigits(sum);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Sum of digits: " << sumOfDigits(number) << endl;
    return 0;
}



