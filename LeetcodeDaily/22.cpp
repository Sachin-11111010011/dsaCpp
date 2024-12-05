class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;

        // Skip underscores in both start and target strings
        while (i < n || j < n) {
            // Move i and j to the next non-underscore character in start and target
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            // If both pointers go out of bounds, we're done
            if (i == n && j == n) {
                return true;
            }

            // If one of the pointers goes out of bounds, return false
            if (i == n || j == n) {
                return false;
            }

            // If the characters at i and j don't match, return false
            if (start[i] != target[j]) {
                return false;
            }

            // Check the movement constraints for 'L' and 'R'
            if (start[i] == 'L' && i < j) {
                return false; // 'L' cannot move right
            }
            if (start[i] == 'R' && i > j) {
                return false; // 'R' cannot move left
            }

            // Move both i and j forward to continue checking
            i++;
            j++;
        }

        return true;
    }
};
