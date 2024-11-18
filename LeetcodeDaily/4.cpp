class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) {
            return result;
        }

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            if (k > 0) {
                for (int j = 1; j <= k; ++j) {
                    sum += code[(i + j) % n];
                }
            } else {
                for (int j = 1; j <= -k; ++j) {
                    sum += code[(i - j + n) % n];
                }
            }
            result[i] = sum;
        }

        return result;
    }
};

//Another Method

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);  // Initialize result with size n and all elements as 0

        if (k == 0) {
            return result;  // If k is 0, return the result as all zeros
        }

        int windowSum = 0;
        int start, end;

        if (k > 0) {
            start = 1;        // Start summing from the next element
            end = k;          // Sum up to k elements
        } else {
            start = n + k;    // Start summing from n + k elements (going backward)
            end = n - 1;      // Sum up to the last element
        }

        // Calculate initial window sum
        for (int pointer = start; pointer <= end; ++pointer) {
            windowSum += code[pointer % n];  // Use modulo n for circular behavior
        }

        // Fill the result array using a sliding window approach
        for (int idx = 0; idx < n; ++idx) {
            result[idx] = windowSum;

            // Slide the window: remove the element going out of the window and add the new element
            windowSum -= code[start % n];
            start++;
            windowSum += code[(end + 1) % n];
            end++;
        }

        return result;
    }
};
