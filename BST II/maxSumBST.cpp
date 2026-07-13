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
    int ans = 0;

    struct Info {
        bool isBST;
        int mn;
        int mx;
        int sum;
    };

    Info dfs(TreeNode* root) {
        // Empty subtree
        if (root == nullptr) {
            return Info(true, INT_MAX, INT_MIN, 0);
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        // Check whether current subtree is BST
        if (left.isBST &&
            right.isBST &&
            left.mx < root->val &&
            root->val < right.mn) {

            int currSum = left.sum + right.sum + root->val;

            ans = max(ans, currSum);

            int currMin = min(left.mn, root->val);
            int currMax = max(right.mx, root->val);

            return Info(true, currMin, currMax, currSum);
        }

        return Info(false, 0, 0, 0);
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};