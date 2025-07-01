class Solution {
public:
    int recursion(vector<vector<int>>& dp,vector<vector<int>>& grid, int m , int n){
        //Base Case
        if(m == 0 && n == 0) return grid[0][0];
        if(m < 0 || n < 0) return 1e5;

        if(dp[m][n] != -1) return dp[m][n];
        int up = grid[m][n] + recursion(dp,grid,m-1,n);
        int left = grid[m][n] + recursion(dp,grid,m,n-1);
        dp[m][n] = min(up,left);
        return dp[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));

        int ans = recursion(dp,grid,m-1,n-1);
        return ans;
    }
};