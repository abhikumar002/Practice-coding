class Solution {
public:

    set<vector<int>> recursion(set<vector<int>>& ans, vector<int>& temp, int index, int n, vector<int>& arr)  
    {
        
        if(index == n){
            ans.insert(temp);
            return ans;
        }


        temp.push_back(arr[index]);
        recursion(ans,temp,index+1,n,arr);
        temp.pop_back();
        recursion(ans,temp,index+1,n,arr);
        return ans;

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        ans = recursion(ans,temp,0,n,nums);
        vector<vector<int>> t(ans.begin(),ans.end());
        return t;
    }
};