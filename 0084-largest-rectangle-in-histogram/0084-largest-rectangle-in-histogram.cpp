class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        
        int max_area = 0;
        int n = h.size();
        stack<int> st;
        if(n < 2) return h[0];

        for(int i=0; i <= n;i++){
            int currentheight = (i==n) ? 0 : h[i];

            while(!st.empty() && h[st.top()] > currentheight){
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top()-1;
                max_area = max(max_area, height * width);
            }

            st.push(i);
        }
        
        return max_area;
    }
};