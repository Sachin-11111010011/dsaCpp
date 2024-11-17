

// Another Method
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<long long> cumulativeSum(n + 1, 0);  // Using n+1 for prefix sum initialization
        int result = INT_MAX;

        // Compute the prefix sum
        for (int i = 0; i < n; ++i) {
            cumulativeSum[i + 1] = cumulativeSum[i] + nums[i];
        }

        for (int j = 0; j <= n; ++j) {
            // Maintain the deque for valid subarray lengths
            while (!deq.empty() && cumulativeSum[j] - cumulativeSum[deq.front()] >= k) {
                result = min(result, j - deq.front());
                deq.pop_front();
            }

            // Maintain monotonicity of the deque
            while (!deq.empty() && cumulativeSum[j] <= cumulativeSum[deq.back()]) {
                deq.pop_back();
            }

            deq.push_back(j);
        }

        return result == INT_MAX ? -1 : result;
    }
};


const int MAX_N = 100000 + 1;

int* nums;

long long st_s[MAX_N];
int pos[MAX_N];

class Solution {
public:
    int shortestSubarray(vector<int>& _nums, int k) {
        int n = _nums.size();
        nums = &_nums[0];
        
        long long sp = 0LL;
        int res = n + 1;

        int b = 0, e = 0;
        st_s[e] = 0;
        pos[e++] = -1;

        for (int i = 0; i < n; i++) {
            sp += nums[i];

            while (b < e && sp - st_s[b] >= k) {
                res = std::min(res, i - pos[b]);
                b++;
            }

            while (b < e && sp <= st_s[e - 1])
                e--;
            st_s[e] = sp;
            pos[e++] = i;
        }

        if (res == n + 1)
            return -1;
        return res;
    }
};