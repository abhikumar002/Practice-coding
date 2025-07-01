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

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> tab(m,vector<int>(n+1,0));

        for(int i=0;i<m;i++){
            if(grid[i][0] == 1) break;
            tab[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            if(grid[0][i] == 1) break;
            tab[0][i] = 1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j] == 1){
                    tab[i][j] = 0;
                    continue;
                }
                tab[i][j] = tab[i-1][j] + tab[i][j-1];
            }
        }
        return tab[m-1][n-1];
    }
};