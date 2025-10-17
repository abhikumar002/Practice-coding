class Solution {
public:
    void recursion(int index, vector<int>& nums, vector<int>& v, vector<vector<int>> & ans) {
        if(index < 0){
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[index]);
        recursion(index-1,nums,v, ans );
        v.pop_back();
        recursion(index-1,nums,v, ans );
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        recursion(n-1,nums,v,ans);
        return ans;
    }
};