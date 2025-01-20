// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         int m=mat.size();
//         int n=mat[0].size();

//         unordered_map<int , int>mp;

//         for(int i=0;i < arr.size(); i++){
//             int val=arr[i];
//             mp[val]=i;
//         }
//         int minIndex=INT_MAX;
        
        
//         for(int row=0;row<m;row++){
//             int lastIndex= INT_MIN;

//             for(int col=0;col < n; col++){
//                 int val=mat[row][col];
//                 int idx= mp[val];
//                 lastIndex=max(lastIndex, idx);
//             }
//             minIndex =min(minIndex ,lastIndex);
//         }
//         for(int col=0;col < n; col++){

//                 for(int row=0;row < m; row++){
//                 int val=mat[row][col];
//                 int idx= mp[val];
//                 lastIndex=max(lastIndex, idx);
//             }
//         }
         
//             minIndex =min(minIndex ,lastIndex);
//     }
//     return minIndex;
// };
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Map to store the position of each number in arr
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = i;
        }

        // Arrays to track the completion of rows and columns
        vector<int> rowProgress(m, 0);
        vector<int> colProgress(n, 0);

        // Store the positions of elements in mat
        unordered_map<int, pair<int, int>> matPositions;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matPositions[mat[i][j]] = {i, j};
            }
        }

        // Process the numbers in arr
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [row, col] = matPositions[num];

            // Update row and column progress
            rowProgress[row]++;
            colProgress[col]++;

            // Check if the row or column is complete
            if (rowProgress[row] == n || colProgress[col] == m) {
                return i; // Return the first index where a row or column is completed
            }
        }

        return -1; // No row or column is fully completed
    }
};
