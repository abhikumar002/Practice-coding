public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        int left = 0, right = 0;
        List<int> ans = new List<int>();
        Dictionary<char,int> sdic = new Dictionary<char,int>();
        Dictionary<char,int> pdic = new Dictionary<char,int>();

        foreach(var x in p){
            pdic[x] = pdic.GetValueOrDefault(x,0)+1;
        }

        while(right < s.Length){
            char c = s[right];
            sdic[c] = sdic.GetValueOrDefault(c,0)+1;

            if(right - left + 1 > p.Length){
                sdic[s[left]]--;
                if(sdic[s[left]]==0) sdic.Remove(s[left]);
                left++;
            }

            if(diccheck(sdic,pdic)) ans.Add(left);
            right++;
        }

        return ans;
    }

    public bool diccheck(Dictionary<char,int> temp1,Dictionary<char,int> temp2){
        if(temp1.Count != temp2.Count) return false;

        foreach(var x in temp1){
            // Console.WriteLine(x.Key + " " + x.Value);
            if(!temp2.ContainsKey(x.Key) || temp2[x.Key] != x.Value)
                return false;
        }
        return true;
    }
}