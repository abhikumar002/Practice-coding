class Solution {
public:

    vector<vector<int>> recursion(vector<vector<int>>& ans, vector<int>& temp, int index, int n, vector<int>& arr){
        
        if(index == n){
            ans.push_back(temp);
            return ans;
        }


        temp.push_back(arr[index]);
        recursion(ans,temp,index+1,n,arr);
        temp.pop_back();
        recursion(ans,temp,index+1,n,arr);
        return ans;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        return recursion(ans,temp,0,n,nums);
    }
};