class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();      // Number of rows in the box
        int n = box[0].size();   // Number of columns in the box
        
        // Create a result matrix with dimensions n x m
        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i) {
            int empty = n - 1;  // Tracks the position of the last empty space in the row
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '#') { 
                    // If it's a stone, move it to the nearest empty space
                    res[empty][m - i - 1] = '#';
                    --empty;
                } else if (box[i][j] == '*') { 
                    // If it's an obstacle, place it and reset the empty tracker
                    res[j][m - i - 1] = '*';
                    empty = j - 1;
                }
            }
        }

        return res;
    }
};
// Another Method
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box.front().size();        
        vector<vector<char>> out(n, vector<char>(m, '.'));

        for (int j = 0; j < m; j++) {
            int fall_to = n-1;
            for (int i = n-1; i >= 0; i--) {
                char cell = box[m-1-j][i];
                if (cell == '*') {
                    out[i][j] = '*';
                    fall_to = i-1;
                }
                else if (cell == '#') {
                    out[fall_to][j] = '#';
                    fall_to--;
                }
            }
        }

        return out;
    }
};