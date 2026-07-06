/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int> > > nodes;
        queue<pair<TreeNode*, pair<int, int> > > q; 
        //.second.first represent hd and .second.second represents lvl
        vector< vector<int> > ans;
        if(root == NULL) return ans;
        q.push({root,{0,0}});

        while(!q.empty()) {
            pair<TreeNode*, pair<int, int> > curr = q.front();
            q.pop();
            TreeNode* temp = curr.first;
            int hd = curr.second.first;
            int lvl = curr.second.second;
            nodes[hd][lvl].push_back(temp->val);

            if(temp->left) q.push({temp->left,{hd-1, lvl+1}});
            if(temp->right) q.push({temp->right,{hd+1, lvl+1}});
        }
        for (const auto& i : nodes) {
            vector<int> col;
            for (const auto& j : i.second) {
                vector<int> temp = j.second;
                sort(temp.begin(), temp.end());
                for (int val : temp) {
                    col.push_back(val);
                }
            }
            ans.push_back(col);
        }
        return ans;

    }
};