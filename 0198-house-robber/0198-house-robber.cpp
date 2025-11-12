class Solution {
public:
    int recursion(int index, vector<int>& nums, vector<int>& dp) {
        if(index < 0) return 0;
        if(index == 0) return nums[index];

        if(dp[index] != -1) return dp[index];
        int take = nums[index] + recursion(index-2, nums, dp);
        int nontake = recursion(index-1, nums, dp);

        dp[index] = max(take, nontake);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return nums[0];
        vector<int> dp(n+1, -1);
        return max(recursion(n-1, nums, dp),recursion(n-2, nums, dp)) ;
    }
};