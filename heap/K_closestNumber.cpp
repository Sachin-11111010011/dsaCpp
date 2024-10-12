#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {5, 6, 7, 8, 9};
    int x = 7;
    int k = 3;
    
    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Max heap to store pairs of (absolute difference, element)
    priority_queue<pair<int, int>> maxh;
    
    // Process the array
    for (int i = 0; i < size; i++) {
        // Push the pair (absolute difference from x, element) into the heap
        maxh.push({abs(arr[i] - x), arr[i]});
        
        // If the heap size exceeds k, remove the top (max difference element)
        if (maxh.size() > k) {
            maxh.pop();
        }
    }

    // Output the k closest elements to x
    while (!maxh.empty()) {
        cout << maxh.top().second << "  ";
        maxh.pop();
    }

    return 0;
}
