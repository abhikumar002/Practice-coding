class Solution {
public:

    void recursion(int index, vector<int>& candidates, set<vector<int>>& hset, vector<int>& temp, int target){
        if(target == 0) { hset.insert(temp); return; }
        if(index >= candidates.size() || target < 0) return;

        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            recursion(index+1,candidates, hset, temp, target - candidates[index]); // take
            temp.pop_back();
        }

        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index]) {
            nextIndex++;
        }
        recursion(nextIndex,candidates, hset, temp, target); // non-take

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        set<vector<int>> hset;
        sort(candidates.begin(),candidates.end());

        recursion(0,candidates, hset, temp, target);

        vector<vector<int>> ans(hset.begin(), hset.end());
        return ans;
    }
};