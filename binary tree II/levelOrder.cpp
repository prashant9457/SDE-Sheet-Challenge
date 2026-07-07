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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> levels;
        if (root == nullptr)
            return levels;

        queue<pair<TreeNode *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;

            for (int i = 0; i < n; i++)
            {
                auto [node, level] = q.front();
                q.pop();

                temp.push_back(node->val);
                if (node->left)
                    q.push({node->left, level + 1});
                if (node->right)
                    q.push({node->right, level + 1});
            }
            levels.push_back(temp);
        }
        return levels;
    }
};