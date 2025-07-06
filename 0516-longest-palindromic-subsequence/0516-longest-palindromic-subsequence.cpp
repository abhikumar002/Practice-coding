class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> tab(n1+1,vector<int>(n2+1,0));

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

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return longestCommonSubsequence(s,s1);
    }
};
//bbbab
//babbb