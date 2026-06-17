class Solution {
    vector<vector<int>> res;
    vector<int> curr;
    int n;
    void f(vector<int>& cd, int i, int target) {
        if(i == n) {
            if(target == 0) res.push_back(curr);
            return;
        }
        //take 
        if(target >= cd[i]){
            curr.push_back(cd[i]);
            f(cd, i+1, target-cd[i]);
            curr.pop_back();
        }
        //notTake
        while(i < n-1 && cd[i] == cd[i+1]) i++;
        f(cd, i+1, target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& cd, int target) {
        
        sort(cd.begin(), cd.end());
        n = cd.size();
        f(cd, 0, target);
        return res;
    }
};