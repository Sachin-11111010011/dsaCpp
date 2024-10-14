#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15}; // Input array
    int k = 3; // Number of largest elements to find
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    // Create a min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minh;

    for (int i = 0; i < size; i++) {
        minh.push(arr[i]); // Push the current element into the min-heap

        // If the size of the heap exceeds k, pop the smallest element
        if (minh.size() > k) {
            minh.pop();
        }
    }

    // Now, the min-heap contains the k largest elements
    cout << "The " << k << " largest elements are: ";
    while (!minh.empty()) {
        cout << minh.top() << " "; // Print the top element
        minh.pop(); // Remove the top element from the heap
    }
    cout << endl;

    return 0; // Return 0 to indicate successful execution
}
