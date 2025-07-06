class Solution {
public:
    
    // int lcs(string text1, string text2, vector<vector<int>>& dp,int n1,int n2){
    //     if(n1 <= -1 || n2 <= -1) return 0;

    //     // cout<<n1<<" "<<n2<<" ";
    //     // cout<<dp[n1][n2]<<endl;
    //     if(dp[n1][n2] != -1) return dp[n1][n2];
    //     int take = 0 ,nontake = 0;

    //     if(text1[n1] == text2[n2]){
    //         take = 1 + lcs(text1,text2,dp,n1-1,n2-1);
    //     }
    //     else{
    //         nontake = max(lcs(text1,text2,dp,n1-1,n2),lcs(text1,text2,dp,n1,n2-1));
    //     }
    //     dp[n1][n2] = max(take,nontake);
    //     return dp[n1][n2];
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length(); //5
        int n2 = text2.length(); // 3
        vector<vector<int>> tab(n1+1,vector<int>(n2+1,0)); //6*3

        for(int i=1;i<=n1;i++){
            int take = 0 ,nontake = 0;
            for(int j=1;j<=n2;j++){         
                if(text1[i-1] == text2[j-1]) take = 1 + tab[i-1][j-1];
                else nontake = max(tab[i-1][j],tab[i][j-1]);
                tab[i][j] = max(take,nontake);
            }
        }
        return tab[n1][n2];
    }
};