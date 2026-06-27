class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) { //no brainer very intutive by statement 
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;//{{position of rooten} , time}
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //get all rotten in q
        for(int i= 0; i<n ; i++) {
            for(int j = 0; j<m ; j++) {
                if(grid[i][j]==2) {
                    q.push({{i, j},0});
                    vis[i][j] = 2;
                }
                
            }
        }

        int time = 0;
        //drow and dcol are just 4 adjacent position vectors
        int drow[] = {-1, 0, 1, 0}; 
        int dcol[] = {0, 1, 0, -1}; 

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            //maximise the time
            time = max(t, time);
            q.pop();
            //go in all 4 direction of a rotton orange
            for(int i= 0; i<4; i++) {
                int nrow = r + drow[i];//new row
                int ncol = c + dcol[i];//new col
                //is not visited and is not rotten condition with out of bound checks
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1 ) 
                    
                {
                    q.push({{nrow, ncol}, t + 1}); //inc the time
                    vis[nrow][ncol] = 2; //rot it
                }
            }

        }
        //check if someone is not rotten after dfs
        for(int i= 0; i<n ; i++) {
            for(int j = 0; j<m ; j++) {
                if(vis[i][j] != 2 && grid[i][j]==1) 
                    return -1;
            }
        }

        return time;
    }
};