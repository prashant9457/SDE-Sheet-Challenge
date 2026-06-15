class Solution {
  public:
    int minPlatform(vector<int> &arr, vector<int>& dep) {
        int n = arr.size();
        int res = 0;

        int maxDep = dep[0];
        for (int i = 1; i < n; i++) {
            maxDep = max(maxDep, dep[i]);
        }
        vector<int> v(maxDep + 2, 0);
        

        for (int i = 0; i < n; i++) {
            v[arr[i]]++;
            v[dep[i] + 1]--;
        }
        
        int count = 0;
        
 
        for (int i = 0; i <= maxDep + 1; i++) {
            count += v[i];
            res = max(res, count);
        }
        
        return res;
    }
};
