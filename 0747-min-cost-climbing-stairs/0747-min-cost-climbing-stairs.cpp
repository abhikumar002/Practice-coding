class Solution {
public:
    // Approach 1
    // int mincost(int index, vector<int>& cost, vector<int>& dp) {
    //     if(index == 1) return cost[1];
    //     if(index == 0) return cost[0];

    //     if(dp[index] != 0) return dp[index];
    //     dp[index] = cost[index] + min(mincost(index-1, cost, dp), mincost(index-2, cost, dp));
    //     return dp[index];
    // }

    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n+1,0);
    //     int ans = min(mincost(n-1, cost, dp), mincost(n-2, cost, dp));
    //     return ans;
    // }

    // Approach 2
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int ans = 0;
    //     int n = cost.size();
    //     vector<int> dp(n+1,0);
    //     dp[1] = cost[1];
    //     dp[0] = cost[0];

    //     for(int i = 2; i<n;i++){
    //        dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
    //     }
    //     return  min(dp[n - 1], dp[n - 2]);
    // }

    // Approach 3
    int minCostClimbingStairs(vector<int>& cost) {
        int ans = 0;
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];

        for(int i = 2; i<n;i++){
           int temp = cost[i] + min(second,first);
           first = second;
           second = temp;
        }
        return  min(first, second);
    }
};