class Solution {
    vector<vector<int>> res;
    vector<int> curr; 
    int n; 
    void f(vector<int>& nums, vector<int>& curr, int i) {
        if(i == n) {
            res.push_back(curr);
            return;
        }
        //include
        curr.push_back(nums[i]);
        f(nums, curr, i+1);

        //not include
        curr.pop_back();
        while(i + 1 < n && nums[i] == nums[i + 1]) i++;
        f(nums, curr, i + 1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        f(nums, curr, 0);
        return res;
    }
};