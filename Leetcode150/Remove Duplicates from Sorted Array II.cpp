class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        for (int x: nums) {
            if (cur < 2 || x != nums[cur - 2]) {
                nums[cur] = x;
                cur++;
            } 
        }
        return cur;
    }
};