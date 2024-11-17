class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minPrice =min(minPrice,prices[i]);
            maxPro =max(maxPro,prices[i]-minPrice);
        }
        return maxPro;
    }
};

// Another Method
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp = prices[0], n = prices.size(), profit = 0;
        for(int i = 1; i < n; i++)
        {
            profit = max(prices[i] - cp, profit);
            cp = min(cp,prices[i]);
        }
        return profit;
    }
};