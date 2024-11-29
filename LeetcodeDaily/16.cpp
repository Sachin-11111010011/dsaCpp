class Solution {
public:
    #define P pair<int, pair<int, int>>
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Early exit condition
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == m - 1 && col == n - 1) {
                return time;
            }

            if (visited[row][col]) {
                continue;
            }
            visited[row][col] = true;

            for (auto& dir : directions) {
                int i = row + dir[0];
                int j = col + dir[1];

                if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
                    continue;
                }

                if (grid[i][j] <= time + 1) {
                    if (time + 1 < result[i][j]) {
                        pq.push({time + 1, {i, j}});
                        result[i][j] = time + 1;
                    }
                } else {
                    int nextTime = (grid[i][j] - time) % 2 == 0 ? grid[i][j] + 1 : grid[i][j];
                    if (nextTime < result[i][j]) {
                        pq.push({nextTime, {i, j}});
                        result[i][j] = nextTime;
                    }
                }
            }
        }

        return -1; // No path to bottom-right corner
    }
}; 

// class Solution {
// public:
//        #define P pair<int,pair<int,int>>  
//        vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

//     int minimumTime(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid.size();

//         if(grid[0][1] > && grid[1][0]>1){
//             return -1;
//         }
//         priority_queue<P,vector<P>,greater<P>> p1;
//         vector<vector<int>> result(m,vector<int>(n,INT_MAX));
//         pq.push({0,{0,0}});
//         result[0][0]=0;
//         vector<vector<int>> visited(m,vector<int>(n,false));
//         while(!pq.empty()){
//             int time=pq.top().first
//             int row=pq.top().second.first;
//             int col=pq.top().second.second;
//             pq.pop();  
//         }
//         if(row== m-1 && col ==n-1){
//             return result[m-1][n-1];
//         }
//         if(visited[row][col]==true){
//             continue;
//         }
//         visited[row][col]=true;
//         for(auto &dir : directions){
//             int i= row+dir[0];
//             int j=col+ dir[1];
//             if(i<0 || i>=m || j<0 || j>=n){
//                 continue;
//             }
//             if(grid[i][j] <= time+1){
//                 pq.push({time+1, {i,j}});
//                 result[i][j] =time+1;
//                  }else if((grid[i][j] -time)%2==0){
//                     pq.push({grid[i][j]+1,{i,j}});
//                     result[i][j] = grid[i][j]+1;  
//                  }else{
//                     pq.push({grid[i][j]});
//                     result[i][j]= grid[i][j];
//                  }
//         }
        
//     }
//     return result[m-1][n-1];    
//     }
// };