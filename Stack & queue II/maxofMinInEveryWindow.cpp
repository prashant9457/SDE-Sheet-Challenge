class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> left, right;

        for (int i = 0; i < n; i++) {
        
            // Previous Smaller
            while (!left.empty() && arr[left.top()] >= arr[i]) left.pop();
            
            prevSmaller[i] = left.empty() ? -1 : left.top();
            left.push(i);
        
            // Next Smaller
            int j = n - 1 - i;
            while (!right.empty() && arr[right.top()] >= arr[j]) right.pop();
            
            nextSmaller[j] = right.empty() ? n : right.top();
            right.push(j);
        }

        vector<int> ans(n, INT_MIN);

        for (int i = 0; i < n; i++) {
            int len = nextSmaller[i] - prevSmaller[i] - 1;
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }
        
        //remaining entries fill
        for (int i = n - 2; i >= 0; i--)
            ans[i] = max(ans[i], ans[i + 1]);
        
        return ans;
    }
};