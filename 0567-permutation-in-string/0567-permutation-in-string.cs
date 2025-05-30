public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        int n = s1.Length;
        if (n > s2.Length) return false;
        
        Dictionary<char,int> s1count = new Dictionary<char,int>();
        Dictionary<char,int> s2count = new Dictionary<char,int>();

         for(int c = 0; c < n; c++){
            s1count[s1[c]] = s1count.GetValueOrDefault(s1[c], 0) + 1;
            s2count[s2[c]] = s2count.GetValueOrDefault(s2[c], 0) + 1;
        }
         
        if(AreDictionariesEqual(s1count,s2count)) return true;
        
        int low = 0;
        for(int right=s1.Length; right<s2.Length; right++){
            s2count[s2[right]] = s2count.GetValueOrDefault(s2[right], 0) + 1;
            s2count[s2[low]]--;

            if(s2count[s2[low]]==0) s2count.Remove(s2[low]);
            low++;
            if(AreDictionariesEqual(s1count,s2count)) return true;
        }

        return false;
    }

    private bool AreDictionariesEqual(Dictionary<char,int> dict1, Dictionary<char,int> dict2) {
        if(dict1.Count != dict2.Count) return false;
        
        foreach(var kvp in dict1) {
            if(!dict2.ContainsKey(kvp.Key) || dict2[kvp.Key] != kvp.Value) {
                return false;
            }
        }
        return true;
    }
}