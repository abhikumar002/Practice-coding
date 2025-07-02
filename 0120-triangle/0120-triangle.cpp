class Solution {
public:
    int recursion(vector<vector<int>>& dp,vector<vector<int>>& triangle, int row, int col){
        if(row == 0 && col == 0) return triangle[0][0];
        if(row < 0 || col < 0 || col > row) return 1e5;

        if(dp[row][col] != -1) return dp[row][col];
        int right = triangle[row][col] + recursion(dp,triangle,row-1,col);
        int left = triangle[row][col] + recursion(dp,triangle,row-1,col-1); 
        dp[row][col] = min(left,right);
        return dp[row][col];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        int ans = INT_MAX;

        for(int i=n;i>=0;i--){
            vector<vector<int>>dp(m,vector<int>(n,-1));
            ans = min(ans,recursion(dp,triangle,m-1,i-1));
        }
        return ans;
    }
};