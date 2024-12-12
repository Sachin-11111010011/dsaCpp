class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(begin(gifts),end(gifts));

        long long sum =0;
        for(int &gift :gifts ){
            sum+= gift;
        }
        long long mySum =0 ;
        while(k--){
            int maxEl=pq.top();
            pq.pop();

            int remaining =sqrt(maxEl);
            mySum+= maxEl - remaining;
            pq.push(remaining);
        }
        return sum - mySum;
    }
};