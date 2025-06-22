class Solution {
public:

    // int recursion(vector<int> & dp, int steps) {
        
    //     if(steps < 0) return 0;
    //     if(steps == 0) return 1;

    //     if(dp[steps] != -1) return dp[steps];
    //     dp[steps] = recursion(dp,steps-1) + recursion(dp,steps-2);
    //     return dp[steps];
    // }

    int climbStairs(int steps) {
        // vector<int> dp(steps+1,-1);
        // dp[0] = 1;
        // dp[1] = 1;

        int first = 1;
        int second = 1;
        int temp = -1;

        for(int i = 2;i<steps+1;i++){
            temp = first + second;
            first = second;
            second = temp;
        }
        return second;
    }
};