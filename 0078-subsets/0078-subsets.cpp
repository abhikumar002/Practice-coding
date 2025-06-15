class Solution {
public:
    void allset(int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){
        if(index==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        allset(index+1,nums,ans,ds);
        ds.push_back(nums[index]);
        allset(index+1,nums,ans,ds);
        ds.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        allset(0,nums,ans,ds);
        
        return ans;
    }
};