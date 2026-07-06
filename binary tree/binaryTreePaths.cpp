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
    void bfs(TreeNode* root, string s, vector<string>& ans) {
        string value = to_string(root->val);

        if(root->left) bfs(root->left, s + value + "->", ans);
        if(root->right) bfs(root->right, s + value + "->", ans);
        if(root->left == NULL && root->right == NULL) ans.push_back(s+value);

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        bfs(root, "", ans);
        return ans;
    }
};