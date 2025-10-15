class Solution {
public:
    string minWindow(string s, string target) {
        int n = s.length();
        if (target.empty() || n < (int)target.size()) return "";

        string temp = "";

        unordered_map<char, int> need;
        for (char c : target) need[c]++;

        int required = target.size();
        int l = 0, minLen = INT_MAX, minStart = 0;

        for (int r = 0; r < n; ++r) {
            if (need[s[r]] > 0) required--;
            need[s[r]]--;

            while (required == 0) {
                int curLen = r - l + 1;
                if (curLen < minLen) {
                    minLen = curLen;
                    minStart = l;
                }

                need[s[l]]++;
                if (need[s[l]] > 0) { // we lost a required char
                    required++;
                }
                l++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);




























        // unordered_map<char,int> umap;

        // for(auto x : target){
        //     umap[x]++;
        // }
        // unordered_map<char,int> t = umap;

        // //while loop check for all character should present in temp;
        // for(int i=0;i<n;i++){
        //     temp = "";

        //     if(t.find(s[i]) != t.end()){
        //         t[s[i]]--;
        //         temp +=s[i];

        //         if(t[s[i]] == 0) t.erase(s[i]);                
        //     }

        //     if(t.size() == 0) break;
        //     q++;
        // }

        // int maxlength = INT_MIN;

        // //shrink until required
        // for(int i=0;i<n;i++){

        //     if(t.find(s[i]) != t.end()){
        //         maxlength = max(maxlength,temp.length());
        //     }
        //     temp.erase(s[i]);

        //     if(t.length() == 0) break;
        //     p++;
        // }

    }
};