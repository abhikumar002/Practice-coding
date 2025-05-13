vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        if(arr.size() < 2) return {-1};
        
        int first = INT_MAX;
        int second = INT_MAX;
        vector<int> ans(2,-1);
        
        
        for(auto x: arr){
            if(x < first){
                first = x;
            }
        }
        
        for(auto x: arr){
            if(x < second and x > first){
                second = x;
            }
        }
        
        ans[0] = first;
        ans[1] = second;
        
        if(first == INT_MAX || second == INT_MAX){
            return {-1};
        }
        return ans;
    }
