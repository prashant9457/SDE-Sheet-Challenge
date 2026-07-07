/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverseLeft(Node* root, vector<int> & ans) {
        //base case considering not to get the last leaf node as it will be in traverseLeaf
        if(root == NULL || (root->left == NULL && root->right == NULL)) return;
        
        ans.push_back(root->data);
        if(root->left)  traverseLeft(root->left, ans);
        else traverseLeft(root->right, ans);
    }
    void traverseLeaf(Node* root, vector<int> &ans) {
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    void traverseRight(Node* root, vector<int> & ans){
        //base condition 
        if(root == NULL || (root->right == NULL && root->left == NULL)) return;
        
        if(root->right) traverseRight(root->right, ans);
        else traverseRight(root->left, ans);
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root->data);
        
        //get left elements
        if(root->left) traverseLeft(root->left, ans);
        //get leaf
        if(root->left || root->right) traverseLeaf(root, ans);
        //get right in reverse
        if(root->right) traverseRight(root->right, ans);
        
        return ans;
    }
};