class Solution {
    // //memoization way
    // int uniquePathsRecursive(int i, int j, int m, int n, vector<vector<int>>& dp) {
    //     if (i == m - 1 && j == n - 1) return 1;
    //     //return memoization
    //     if (dp[i][j] != -1) return dp[i][j];
        
    //     int rightPaths = 0;
    //     int downPaths = 0;
    //     //if path exists
    //     if (i < m - 1) rightPaths = uniquePathsRecursive(i + 1, j, m, n, dp);
    //     if (j < n - 1) downPaths = uniquePathsRecursive(i, j + 1, m, n, dp);
    //     //sum up the paths
    //     dp[i][j] = rightPaths + downPaths;
    //     return dp[i][j];
    // }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return uniquePathsRecursive(0, 0, m, n, dp);

        //bottom-up
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};