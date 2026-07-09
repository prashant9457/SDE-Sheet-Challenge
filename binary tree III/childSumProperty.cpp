/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution
{

public:
    bool isSumProperty(Node *root)
    {
        // code here
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 1;

        int sum = 0;

        if (root->left != nullptr)
            sum += root->left->data;

        if (root->right != nullptr)
            sum += root->right->data;

        return ((root->data == sum) && isSumProperty(root->left) && isSumProperty(root->right));
    }
};