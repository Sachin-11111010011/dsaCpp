#include <bits/stdc++.h>
using namespace std;

class Customer {
    string name;
    int account_number, balance;
    static int total_customer;
    static int total_balance;

public:
    Customer(string name, int account_number, int balance) {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customer++;
        total_balance += balance;
    }

    static void accStatic() {
        cout << "Total number of Customers: " << total_customer << endl;
        cout << "Total Balance: " << total_balance << endl;
    }

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            total_balance += amount;
        }
    }

    void withdrawal(int amount) { 
        if (amount <= balance && amount > 0) { 
            balance -= amount;
            total_balance -= amount;
        }
    }

    void display() {
        cout << name << " " << account_number << " " << balance << " Total Balance: " << total_balance << endl;
    }

    void display_total() {
        cout << "Total number of Customers: " << total_customer << endl;
    }
};

int Customer::total_customer = 0;
int Customer::total_balance = 0;

int main() {
    Customer A1("Sachin", 1, 1000);
    Customer A2("Bachin", 2, 1050);
    Customer A3("Dachin", 3, 1100);
    
    A1.deposit(800);
    A1.withdrawal(500);
    Customer::accStatic();

    return 0;
}
