//Brute Force Code 
class Solution {
private:
    bool isPrefixAndSuffix(string& s, string& t){
        int n = s.length();
        int m = t.length();
        
        return (n <= m && t.substr(0, n) == s && t.substr(m - n, n) == s);
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i < j && isPrefixAndSuffix(words[i], words[j]))
                    ans++;
            }
        }

        return ans;
    }
};

