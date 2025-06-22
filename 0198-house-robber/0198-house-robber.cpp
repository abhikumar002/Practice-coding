class Solution {
public:
    // int recursion(vector<int>& dp, int n, vector<int>& nums) {
        
    //     if(n < 0) return 0;
    //     if(n == 0) return nums[n];

    //     if(dp[n] != -1) return dp[n];
    //     int take = nums[n] + recursion(dp,n-2,nums);
    //     int nontake = recursion(dp,n-1,nums);

    //     dp[n] = max(take,nontake);
    //     return dp[n];
    // }

    int rob(vector<int>& nums) {
        // 1 2 3 1
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> tempo(n+1,0);
        tempo[0] = nums[0];
        tempo[1] = max(nums[1],nums[0]);
        int ans = INT_MIN;

        for(int i=2;i<n;i++){
           tempo[i] = max(nums[i] + tempo[i-2],tempo[i-1]);
        }
        return tempo[n-1];
    }
};