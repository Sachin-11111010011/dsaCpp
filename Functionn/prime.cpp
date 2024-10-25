#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    if (prime(a)) {
        cout << a << " is a prime number.\n";
    } else {
        cout << a << " is not a prime number.\n";
    }

    return 0;
}
