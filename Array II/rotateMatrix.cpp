class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        //transpose
        for(int i = 0; i<n ; i++)
            for(int j = i+1; j<n; j++) 
                swap(mat[i][j],mat[j][i]);
        //reverse  
        for(int i = 0; i<n; i++) 
            for(int st = 0, end = n-1 ; st < end;) 
                swap(mat[i][st++], mat[i][end--]);
            
    }
        
};