#include <iostream>
using namespace std;

class BankAccount {
    int balance;

    public:
        BankAccount() : balance(0) {} 

        BankAccount(int bal) : balance(bal) {}

        BankAccount(const BankAccount& other) {
            balance = other.balance;
        }

        int getBalance() {
            return balance;
        }

        void deduct (int amount) {
            if (amount <= balance) {
                balance -= amount;
            } else {
                cout << "Insufficient funds!" << endl;
            }
        }
};

int main(){
    BankAccount account1;
    cout << "Account 1 balance: $" << account1.getBalance() << endl;

    BankAccount account2(1000);
    cout << "Account 2 balance: $" << account2.getBalance() << endl;

    BankAccount account3 = account2;
    cout << "Account 3 balance: $" << account3.getBalance() << endl;

    account3.deduct(200);
    cout << "Account 3 balance after deduction: $" << account3.getBalance() << endl;
    cout << "Account 2 balance remains: $" << account2.getBalance() << endl;
    
    return 0;
}

