class Solution {
public:
    //Approch 1: (Recursive) + DP
    // int StairsRecursive(int index,int n, int& ans,  vector<int>& v) {
    //     if(index == n){ return 1; }
    //     if(index > n){ return 0; }
        
    //     if(v[index] != -1) return v[index];
    //     v[index] = StairsRecursive(index+1, n, ans, v) + StairsRecursive(index+2, n, ans, v);

    //     return v[index];
    // }

    // Approch 2: (Top-Down) + DP
    // int climbStairs(int n) {
    //     int ans = 0;
    //     vector<int>dp(n+1,-1);
    //     dp[0] = 1;
    //     dp[1] = 1;

    //     for(int i=2; i<n+1; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }

    //     return dp[n];
    // }

    // Approch 3:(Top-Down)
    int climbStairs(int n) {
        int ans = 0;
        int temp = -1;
        int first = 1;
        int second = 1;

        for(int i=2; i<n+1; i++) {
            temp = first + second;
            first = second;
            second = temp;
        }

        return second;
    }
};