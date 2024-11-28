// class Solution {
// public:
//     int minimumObstacles(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();

//         vector<vector<int>> result(m , vector<int>(n,INT_MAX));
//         result[0][0]=0;
//         priority_queue<P ,vector<P> , greater<P>> pq;
//         pq.push({0,{0,0}});
//         while(!pq.empty()){
//             auto curr =pq.top();
//             pq.pop();
//              int d=curr.first;
//              int i=curr.second.first;
//              int j=curr.second.second;
//              for(auto &dir :directions){
//                 int x=i + dir[0];
//                 int y=j + dir[1];
//                 if(x<0 || x>=m || y<0 || y>=n){
//                     continue;
//                 }
//                 int wt =(grid[x][y] == 1) ? 1:0;

//                 if(d+wt < result[x][y]){
//                     result[x][y] = d+wt;
//                     pq.push({d+wt,{x,y}});
//                 }
//              }
//         }
//         return result[m-1][n-1]
//     }
// };
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Type alias for readability
        using P = pair<int, pair<int, int>>;

        // Direction vectors for moving in 4 possible directions.
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // 2D vector to store the minimum number of obstacles to reach each cell.
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        result[0][0] = 0;

        // Priority queue for Dijkstra's algorithm.
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for (auto& dir : direction) {
                int x = i + dir[0];
                int y = j + dir[1];

                // Check bounds.
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                // Weight depends on whether the cell is an obstacle.
                int wt = (grid[x][y] == 1) ? 1 : 0;

                // If a shorter path is found, update and push to the queue.
                if (d + wt < result[x][y]) {
                    result[x][y] = d + wt;
                    pq.push({d + wt, {x, y}});
                }
            }
        }

        return result[m - 1][n - 1];
    }
};