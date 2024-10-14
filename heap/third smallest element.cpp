#include<bits/stdc++.h>
using namespace std;

int main() {
    // Define the array and its size
    int arr[] = {3, 6, 9, 2, 12, 56};  // Array with 6 elements
    int size = sizeof(arr) / sizeof(arr[0]);  // Size of the array
    
    int k = 3;  // We are finding the third smallest element
    
    // Create a max-heap (priority queue by default is a max-heap)
    priority_queue<int> maxh;
    
    // Process the array
    for (int i = 0; i < size; i++) {
        maxh.push(arr[i]);  // Insert elements into the max-heap
        
        // If the heap size exceeds k, remove the largest element
        if (maxh.size() > k) {
            maxh.pop();
        }
    }
    
    // The root of the max-heap will be the third smallest element
    cout << "The third smallest element is: " << maxh.top() << endl;

    return 0;  // Successful execution
}
