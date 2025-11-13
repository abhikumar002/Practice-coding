class Solution {
public:

    //Approach 1 : Recursion + DP
    int recursion(int left,int right, int index, vector<int>& nums, vector<int>& dp) {
        if(index < left) return 0;

        if(dp[index] != -1) return dp[index];
        int take = nums[index] + recursion(left, right, index-2, nums, dp);       
        int nontake = recursion(left, right, index-1, nums, dp);

        dp[index] = max(take, nontake);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return nums[0];
        vector<int> dpA(n+1, -1);
        int caseA = recursion(1, n-1, n-1, nums, dpA);

        vector<int> dpB(n+1, -1);
        int caseB = recursion(0, n-2, n-2, nums, dpB);

        return max(caseA, caseB);

    }
};