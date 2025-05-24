public int LengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        Dictionary<char,int> count = new Dictionary<char,int>();

        for(int right =0;right<s.Length;right++){
            char c = s[right];
            if(count.ContainsKey(c)){
                count[c] += 1;
            }
            else{
                count[c] = 1;
            }

            while(count[c] > 1){
                char leftchar = s[left];
                count[leftchar] = count[leftchar]-1;
                left++;
            }

            ans = Math.Max(ans,right-left+1);
        }

        return ans;
    }
