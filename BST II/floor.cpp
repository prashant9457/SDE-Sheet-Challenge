/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        
        while(root) 
        {
            if(root->data > k) 
                root = root->left;
            else {
                ans = root->data;
                root = root->right;
            }
        }
        return ans;
    }
};