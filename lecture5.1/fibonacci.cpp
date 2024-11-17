
   #include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    // Variables to store the current and previous terms
    int prev = 0, curr = 1, last;

    // Check if the number of terms is valid
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else if (n == 1) {
        cout << "Fibonacci series: " << prev << endl;
    } else {
        cout << "Fibonacci series: " << prev << ", " << curr;

        // Loop to generate Fibonacci terms
        for (int i = 1; i <= n; ++i) {
            last = prev + curr; // Calculate the next term
            cout << ", " << last; // Print the next term
            prev = curr;         // Update previous term
            curr = last;         // Update current term
        }
        cout << endl;
    }

    return 0;
}
