class Solution {

    bool colorIsSafe(int node, int color, vector<int>& col, vector<vector<int>>& adj) {
        for (int ind : adj[node]) if(col[ind] == color) return false;
        return true;
    }

    bool solve(int node, int n, int m, vector<int>& col, vector<vector<int>>& adj) {

        if (node == n) return true;

        for (int color = 1; color <= m; color++) {

            if (colorIsSafe(node, color, col, adj)) { 
                col[node] = color;
                if (solve(node + 1, n, m, col, adj)) return true;
                col[node] = 0; // backtrack
            }
            
        }

        return false;
    }

public:
    bool graphColoring(vector<vector<int>>& edges, int m, int n) {

        vector<vector<int>> adj(n);
        vector<int> col(n, 0);
        //conerting edges into adj list
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return solve(0, n, m, col, adj);
    }
};