class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            int count = 0;
            while(i<n && nums[i] == 1) {count++; i++;}
            mx = max(mx, count);
        }
        return mx;
    }
};