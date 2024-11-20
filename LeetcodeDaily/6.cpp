class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), j = 0;
        int ans = n, window = 0;
        std::unordered_map<char,int> count;

        for(auto &c : s) count[c]++;

        if(count['a'] < k || count['b'] < k || count['c'] < k) return -1;

        for(int i = 0; i < n; i++) {
            count[s[i]]--;
            window++;
            while(count[s[i]] < k) {
                count[s[j++]]++;
                window--;
            }
            ans = std::min(ans, n - window);
        }

        return ans;
    }
};