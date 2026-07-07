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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        bool even = true;

        while(!q.empty()) {
            int n = q.size();
            vector<int> level (n);

            for(int i = 0; i<n; i++) {
                TreeNode* top =  q.front();
                q.pop();

                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);

                int index = (even) ? i : n-i-1;
                level[index] = top->val;

            }
            even = (even) ? false : true;
            ans.push_back(level);
        }
        
        return ans;
    }
};