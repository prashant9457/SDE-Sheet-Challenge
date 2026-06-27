class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //push front for increasing fashion.
        //push back is for smaller element.
        deque<int> dq;//will store index
        vector<int> ans;

        for(int i = 0; i<nums.size(); i++) {
            while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);

            if(dq.front() <= i - k) dq.pop_front();
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};