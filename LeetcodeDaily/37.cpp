// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n=arr.size();

//         vector<int> prefixMax(begin(arr),end(arr));
        
//         vector<int> suffixMin(begin(arr),end(arr));

//         for(int i=1;i<n;i++){
//             prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);

//         }
//         for(int i=n-2;i>=0;i--){
//             suffixMin[i] =min(suffixMin[i],suffixMin[i+1]);
//         }   
//         int count =0;
//         for(int i=0;i<n;i++){
//             int pehlekaMax= i > 0? prefixMAx[i-1] : -1;
//             int baddkaMin=suffixMin[i];
//             if(pehleMax < baddkaMin){
//                 count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        // Create prefixMax and suffixMin arrays
        vector<int> prefixMax = arr;
        vector<int> suffixMin = arr;

        // Fill prefixMax with maximum values up to the current index
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);
        }

        // Fill suffixMin with minimum values from the current index to the end
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i], suffixMin[i + 1]);
        }

        // Count the number of chunks
        int count = 0;
        for (int i = 0; i < n; i++) {
            int pehlekaMax = i > 0 ? prefixMax[i - 1] : INT_MIN;
            int baddkaMin = suffixMin[i];
            if (pehlekaMax <= baddkaMin) {
                count++;
            }
        }

        return count;
    }
};
