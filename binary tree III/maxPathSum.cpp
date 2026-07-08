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
    
    int bfs(TreeNode* root, int &ans) {
        if(root==nullptr) return 0;

        int left = 0;
        int right = 0;
        //to handle negative max(0, bfs()) is most important what i missed
        if(root->left) left = max(0, bfs(root->left, ans));
        if(root->right) right = max(0, bfs(root->right, ans));

        ans = max(ans, root->val + left + right);
        return root->val + max(left , right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        bfs(root, ans);
        return ans;
    }
};