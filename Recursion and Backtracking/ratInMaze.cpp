class Solution {
    vector<string> ans;
 
    void helper(vector<vector<int>>& maze, int r, int c, string path) {
        int n = maze.size();

        if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || maze[r][c] == -1)
            return;

        if (r == n - 1 && c == n - 1) {ans.push_back(path); return;}

        maze[r][c] = -1;

        helper(maze, r + 1, c, path + "D");
        helper(maze, r - 1, c, path + "U");
        helper(maze, r, c - 1, path + "L");
        helper(maze, r, c + 1, path + "R");

        maze[r][c] = 1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        string path = ""; 
        int n = maze.size();
        // vector<vector<bool>> vis(n, vector<bool>(n, false));
        helper(maze, 0, 0, path);
        sort(ans.begin(), ans.end());
        
        return ans;
        
        
    }
};