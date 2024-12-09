class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>pairsCount(nums.size(),0);
        vector<bool> isSpecial(queries.size(), true);

        for(int i=1,j=0;i<nums.size();i++)
        {
            if((nums[i]%2)==(nums[i-1]%2))
            {
                j++;
            }
            pairsCount[i] = j;
        }
        for(int i=0;i<queries.size();i++)
        {
            int startIndex=queries[i][0];
            int endIndex=queries[i][1];
            if(pairsCount[startIndex] !=pairsCount[endIndex])
            {
                isSpecial[i]=false;
            }
        }
        return isSpecial;
    }
};