public int longestKSubstr(string s, int k) {
        // your code here
        int ans = -1;
        int left = 0,right = 0;
        Dictionary<int,int> dic = new Dictionary<int,int>();
        
        while(right < s.Length){
            dic[s[right]] = dic.GetValueOrDefault(s[right], 0) + 1;
            
            if(dic.Count < k){
             right++;
             continue;   
            }
            
            while(dic.Count !=0 && dic.Count > k){
                dic[s[left]]--;
                if(dic[s[left]]==0) dic.Remove(s[left]);
                left++;
            }
            
            ans = Math.Max(ans,right-left+1);
            right++;
        }
        
        return ans;
    }
