public class Solution {
    public int CharacterReplacement(string s, int k) {
        Dictionary<char,int> freq = new Dictionary<char,int>();
        int ans = 0, low = 0, maxfreq = 0;

        for(int high=0;high<s.Length;high++){
            char c = s[high];
            if (freq.ContainsKey(c)) {
                freq[c]++;
            }
            else{
                freq[c] = 1;
            }

            maxfreq = Math.Max(maxfreq,freq[c]);
            
            while((high - low + 1) - maxfreq > k){
                freq[s[low]]--;
                low++;
            }

            ans = Math.Max(ans, high - low + 1);
        }

        return ans;
    }
}