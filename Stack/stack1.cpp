#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElementRight(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> s;

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Remove elements from the stack smaller than the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack is not empty, top of stack is the next greater element
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push current element onto the stack
        s.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElementRight(arr);

    for (int i : result) {
        cout << i << " ";
    }
    // Output: 5 10 10 -1 -1
    return 0;
}
