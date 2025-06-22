class Solution {
public:

    int recursion(vector<int> & dp, int steps) {
        
        if(steps < 0) return 0;
        if(steps == 0) return 1;

        if(dp[steps] != -1) return dp[steps];
        dp[steps] = recursion(dp,steps-1) + recursion(dp,steps-2);
        return dp[steps];
    }

    int climbStairs(int steps) {
        vector<int> dp(steps+1,-1);
        return recursion(dp,steps);
    }
};