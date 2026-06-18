class Solution {
    int n ;
    vector<vector<int>> res;
    void getPerms(vector<int> &nums, int ind) {
        if(ind == n) {res.push_back(nums); return;}

        for(int i = ind; i<n; i++) {
            swap(nums[ind], nums[i]);
            getPerms(nums, ind+1);
            swap(nums[ind], nums[i]);//backtrack changes
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        getPerms(nums, 0);
        return res;
    }
};