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

    int tabulation(int start, int end, vector<int>& nums){
        int n = end-start+1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];


        vector<int>tab(n+1,0);
        tab[0] = nums[start];
        tab[1] = max(nums[start],nums[start+1]);

        for(int i=2;i<n;i++){
            tab[i] = max(tab[i - 1], tab[i - 2] + nums[start + i]);
        }

        return tab[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; 
        if(n == 2) return max(nums[0],nums[1]);

        int ans = tabulation(0, n-2,nums);
        int ans1 = tabulation(1, n-1,nums);

        return max(ans,ans1);
    }
};