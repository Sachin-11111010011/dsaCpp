// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n =nums.size();
        
//         long long result=0;
//         long long currWindowSum=0;

//         unordered_set<int> st;

//         int i=0;
//         int j=0;
//         while(j<n){
//         while(st.count(nums[j])){
//             currWindowSum -= nums[i];
//             st.erase(nums[i]);
//             i++;
//         }
//         currWindowSum+=nums[j];
//         st.insert(nums[j]);

//         if(j-i+1 ==k){
//             result =max(result,currWindowSum);

//             currWindowSum -= nums[i];
//             st.erase(nums[i]);
//             i++;
//         }
//         j++;
//     }
// };

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long result = 0;
        long long currWindowSum = 0;
        unordered_set<int> st;

        int i = 0; // Start of the window
        int j = 0; // End of the window

        while (j < n) {
            // Remove elements until there are no duplicates
            while (st.count(nums[j])) {
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            // Add the current element to the set and window sum
            currWindowSum += nums[j];
            st.insert(nums[j]);

            // Check if the window size is equal to k
            if (j - i + 1 == k) {
                result = max(result, currWindowSum);

                // Remove the element at the start to maintain the window size
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            // Expand the window
            j++;
        }

        return result;
    }
};
