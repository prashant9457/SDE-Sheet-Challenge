class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //maintain a st 
        stack<int> st;
        int ans = 0;
        heights.push_back(0);

        for(int i = 0; i<heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();

                int len = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height*len);
            }
            
            st.push(i);
        }

        return ans;
    }
};