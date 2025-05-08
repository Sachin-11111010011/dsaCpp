class Solution {
    public:
      int findMissing(vector<int> &arr) {
          int n = arr.size();
          if (n < 2) return -1; // Not enough elements
  
          // Step 1: Compute minimum adjacent difference (common difference)
          int d = INT_MAX;
          for (int i = 1; i < n; ++i) {
              d = min(d, arr[i] - arr[i - 1]);
          }
  
          // Step 2: Check if already a complete AP
          bool complete = true;
          for (int i = 1; i < n; ++i) {
              if (arr[i] - arr[i - 1] != d) {
                  complete = false;
                  break;
              }
          }
  
          if (complete) {
              // Already complete → return next expected element
              return arr[n - 1] + d;
          }
  
          // Step 3: Binary Search to find the missing element
          int low = 0, high = n - 1;
  
          while (low < high) {
              int mid = low + (high - low) / 2;
              int expected = arr[0] + mid * d;
  
              if (arr[mid] == expected) {
                  low = mid + 1;
              } else {
                  high = mid;
              }
          }
  
          // Step 4: Return the missing element
          return arr[0] + low * d;
      }
  };
  