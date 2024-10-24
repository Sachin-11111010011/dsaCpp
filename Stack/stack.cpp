#include <iostream>
#include <stack>
using namespace std;

void nextGreaterElement(int arr[], int n) {
    stack<int> s;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            result[i] = -1;
        else
            result[i] = s.top();

        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " --> " << result[i] << endl;
}

int main() {
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreaterElement(arr, n);
    return 0;
}
