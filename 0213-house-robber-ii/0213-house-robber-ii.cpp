class Solution {
public:
    int recursion(vector<int>& dp, int n, vector<int>& nums) {    
        if(n < 0) return 0;
        if(n == 0) return nums[n];

        if(dp[n] != -1) return dp[n];
        int take = nums[n] + recursion(dp,n-2,nums);
        int nontake = recursion(dp,n-1,nums);

        dp[n] = max(take,nontake);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; 
        if(n == 2) return max(nums[0],nums[1]);

        vector<int> front(nums.begin(),nums.end()-1);
        vector<int> end(nums.begin()+1,nums.end());
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);

        return max(recursion(dp1,n-2,front),recursion(dp2,n-2,end));
    }
};