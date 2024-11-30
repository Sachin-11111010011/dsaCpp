// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int jumps=0;
//         int current=0;
//         int farthest=0;

//         for(int i=0;i<nums.size();i++){
//             farthest=max(farthest,nums[i]+i);
//             if(i==current){
//                 current=farthest;
//                 jumps++;
//             }
//         }
//         return jumps;
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            farthest = max(farthest, nums[i] + i);
            
            // If we reach the current boundary, we make a jump
            if (i == current) {
                if (current != nums.size() - 1) { // Avoid unnecessary jump at the last element
                    current = farthest;
                    jumps++;
                }
            }
        }
        return jumps;
    }
};
