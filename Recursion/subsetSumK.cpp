class Solution{ 
    int n;
    bool f(vector<int> &arr, int ind, int target, vector<vector<int>>& dp) {
        if(ind == n) return  dp[ind][target] =  (target == 0) ? true : false;

        if(dp[ind][target] != -1) return dp[ind][target];

        bool notTake = f(arr, ind+1, target, dp);
        bool take = false;
        if(arr[ind] <= target) take = f(arr, ind+1, target - arr[ind], dp);

        return dp[ind][target] = take || notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        n = arr.size();
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        
        return f(arr, 0, target, dp);
    }
};