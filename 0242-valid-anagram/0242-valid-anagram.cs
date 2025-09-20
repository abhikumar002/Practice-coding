public class Solution {
    public bool IsAnagram(string s, string t) {
        Dictionary<char,int> dic = new Dictionary<char,int>();

        for(int i=0;i<s.Length;i++){
            if(!dic.ContainsKey(s[i])){
                dic[s[i]] = 0;
            }

            dic[s[i]]++;
        }

        for(int i=0;i<t.Length;i++){
            if(!dic.ContainsKey(t[i])) return false;
            dic[t[i]]--;
            if(dic[t[i]]==0) dic.Remove(t[i]);
        }

        return dic.Count == 0;
    }
}