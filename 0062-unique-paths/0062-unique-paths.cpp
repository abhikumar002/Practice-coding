class Solution {
public:
    int recursion(vector<vector<int>>& dp,int m,int n){
    // cout<<m<<" "<<n<<endl;
    if(m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;

    if(dp[m][n] !=-1) return dp[m][n];
    dp[m][n] = recursion(dp,m-1,n) + recursion(dp,m,n-1);
    return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1)); 
        int ans = recursion(dp,m-1,n-1);
        return ans;
    }
};