class Solution {
public:


void markGuarded(int row, int col,vector<vector<int>> & grid){
    int m= grid.size();
    int n=grid[0].size();
    vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};

    for(auto[dx,dy] : directions){
        int x=row,y=col;
        while(true){
            x+=dx;
            y+=dy;
            if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==2 ||grid[x][y]==3){
                break;
            }
            grid[x][y]=1;
        }
    }
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));

        for(auto& guard : guards){
            grid[guard[0]][guard[1]]=2;
        }
        for(auto& wall :walls){
            grid[wall[0]][wall[1]]=3;
        }
        for(auto& guard :guards){
            markGuarded(guard[0], guard[1],grid);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};