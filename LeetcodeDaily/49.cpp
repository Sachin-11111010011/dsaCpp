// class Solution {
// public:
//     int Z , O;
//     int L , H;

//     const int M=1e9+7;

//     int solve(int l, vector<int>&t){
//         if(l>H)
//         return 0;

//         if(t[l] != -1){
//             return t[l];
//         }
//         bool addOne=false;

//         if(l>=L && l<=H){
//             addOne=true;
//         }
        
//         int append_zero=solve(l+Z,t);
//         int append_one=solve(l+0,t);

//         return t[l] =(addOne + append_zero + append_one) % M;
//     }



//     int countGoodStrings(int low, int high, int zero, int one) {
//         L=low;
//         H=high;
//         Z=zero;
//         O=one;
//         vector<int> t(high+1, -1);
//         return solve(0,t);
//     }
// };

class Solution {
public:
    int Z, O;
    int L, H;

    const int M = 1e9 + 7;

    int solve(int l, vector<int>& t) {
        // Base case: If l exceeds the high boundary, stop recursion.
        if (l > H)
            return 0;

        // If already computed, return the cached value.
        if (t[l] != -1) {
            return t[l];
        }

        // Determine if adding this length contributes to the result.
        bool addOne = (l >= L && l <= H);

        // Recursive calls: Extend the current string by 'zero' or 'one'.
        int append_zero = solve(l + Z, t);
        int append_one = solve(l + O, t);

        // Compute the total count and store in memoization table.
        return t[l] = (addOne + append_zero + append_one) % M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Initialize global variables and memoization table.
        L = low;
        H = high;
        Z = zero;
        O = one;
        vector<int> t(high + 1, -1);
        return solve(0, t);
    }
};
