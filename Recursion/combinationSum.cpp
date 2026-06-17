class Solution {
    vector<vector<int>> res;
    vector<int> curr; 
    int n;
    void f(vector<int>& candidates, int i, int target) {
        if(target == 0) {res.push_back(curr); return;}
        if(i == n) return;

        //take 
        if(target >= candidates[i]) { 
            curr.push_back(candidates[i]);
            f(candidates, i, target - candidates[i]);
            curr.pop_back();//backtrack
        } 
        //not take          
        f(candidates, i+1, target);      
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        f(candidates, 0, target);
        return res;
    }
};