class Solution {
public:

    int expand(string s, int left, int right){

        while(left>= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left -1;
    }

    string longestPalindrome(string s) {
        
        int n = s.length();
        if(n == 1) return s;

        int ans = INT_MIN;
        int left = 0;
        int right = 0;
        
        for(int i=0;i<s.length()-1;i++){
            int len1 = expand(s,i,i); //odd
            int len2 = expand(s,i,i+1); //even

            int window = max(len1,len2);
            if(right - left < window){
               left = i - (window - 1) / 2;
               right = i + window / 2;
            }  
        }

        return s.substr(left,right-left+1);
    }

};