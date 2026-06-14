class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i<n; i++) {
            while(i < n-1 && nums[i]==nums[i+1]) i++;
            nums[cnt++] = nums[i];
        }
        return cnt;
    }
};