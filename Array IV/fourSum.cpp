class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //four pointer approach

        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans; 

        for(int i = 0; i<n-3; i++) {

            if(i>0 && nums[i] == nums[i-1]) continue; //duplicates i handling

            for(int j = i+1; j<n-2; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue; //duplicates j handling
                
                int k = j+1;
                int l = n-1;
                while(k<l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum < target) k++;
                    else if(sum > target) l--;
                    else {
                        ans.push_back({nums[i] , nums[j] , nums[k] , nums[l]});
                        while(k<l && nums[k] == nums[k+1]) k++;//duplicates k handling
                        while(k<l && nums[l] == nums[l-1]) l--;//duplicates l handling
                        k++;
                        l--;
                    }
                }
            }
 
        }
        return ans;
    }
};