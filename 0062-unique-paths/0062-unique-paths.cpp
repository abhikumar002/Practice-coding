class Solution {
public:
    // int recursion(vector<vector<int>>& dp,int m,int n){
    // // cout<<m<<" "<<n<<endl;
    // if(m == 0 && n == 0) return 1;
    // if(m < 0 || n < 0) return 0;

    // if(dp[m][n] !=-1) return dp[m][n];
    // dp[m][n] = recursion(dp,m-1,n) + recursion(dp,m,n-1);
    // return dp[m][n];
    // }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1)); 
        vector<vector<int>> tab(m,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            tab[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            tab[0][i] = 1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                tab[i][j] = tab[i-1][j] + tab[i][j-1];
            }
        }
        return tab[m-1][n-1];
    }
};