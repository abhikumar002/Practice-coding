class Solution {
public:
    void recursion(int index, vector<int>& temp, set<vector<int>>& st, vector<int>& nums){

        st.insert(temp);
        
        if(index == nums.size())  return;

        temp.push_back(nums[index]);
        recursion(index+1, temp, st, nums);
        temp.pop_back();
        recursion(index+1, temp, st, nums);

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());

        recursion(0, temp, st, nums);
        vector<vector<int>> ans(st.begin(),st.end());

        return ans;
    }
};