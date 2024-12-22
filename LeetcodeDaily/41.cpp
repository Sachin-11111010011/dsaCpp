// class Solution {
// public:
//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         vector<vector<vector<int>>> qs(heights.size());
//         priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>>  pq;

//         for(int q=0;q< queries.size(); q++){
//             int a=queries[q][0] ,b =queries[q][1];
//             int mini= min(a,b), maxi =max(a,b);

//             if(mini == maxi || heights[maxi] > heights[mini]) res[q] =maxi;
//             else{
//                 qs[maxi].push_back({ max(heights[mini], heights[maxi]), q});
//             }
//         }
//         for(int i=0; i< heights.size() ; i++){
//             while(!pq.empty() && pq.top()[0] < heights[i]){
//                 res[pq.top() [1]] =i;
//                 pq.top();
//             }
//             for(auto ele: qs[i]){
//                 pq.push(ele);
//             }
//         }
//         return  res;
//     }
// };

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = heights.size();
        vector<int> res(n, -1); // Initialize result with default values
        vector<vector<vector<int>>> qs(m); // Queries categorized by index
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Process each query
        for (int q = 0; q < n; q++) {
            int a = queries[q][0], b = queries[q][1];
            int mini = min(a, b), maxi = max(a, b);

            if (mini == maxi || heights[maxi] > heights[mini]) {
                res[q] = maxi; // Direct result for this query
            } else {
                // Push relevant queries to qs
                qs[maxi].push_back({max(heights[mini], heights[maxi]), q});
            }
        }

        // Iterate over heights and resolve queries
        for (int i = 0; i < m; i++) {
            // Process priority queue
            while (!pq.empty() && pq.top()[0] < heights[i]) {
                res[pq.top()[1]] = i; // Set result for the query
                pq.pop(); // Remove processed element
            }
            // Push current queries into the priority queue
            for (auto& ele : qs[i]) {
                pq.push(ele);
            }
        }

        return res; // Return the results
    }
};
