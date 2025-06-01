public class Solution {
    public int CharacterReplacement(string s, int k) {
        int ans = 0, left = 0, right =0, maxfreq = 0;
        Dictionary<char,int> freq = new Dictionary<char,int>();

        while(right<s.Length){
            
            char c = s[right];
            freq[c] = freq.GetValueOrDefault(c,0)+1;

            maxfreq = Math.Max(maxfreq,freq[c]); 

            while((right - left + 1) - maxfreq > k){
                freq[s[left]]--;
                left++;
            }

            ans = Math.Max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
}