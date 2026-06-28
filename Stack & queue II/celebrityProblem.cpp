class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int cand = 0;
        int n = mat.size();
        
        for(int i = 0; i<n; i++) 
            if(mat[cand][i] == 1) cand = i;
        
        for(int i = 0 ; i<n; i++) 
            if(i != cand && (mat[cand][i] == 1 || mat[i][cand] == 0)) return -1;
        
        return cand;
    }
};