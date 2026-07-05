/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans;
        
        map<int, int> mp; // {horizontal distance, node value}
        
        queue<pair<Node*, int>> q; // {node, horizontal distance}
        q.push({root, 0});
        
        while(!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            
            // overwrite new level values if appear later
            mp[level] = node->data;
            
            if(node->left) {
                q.push({node->left, level - 1});
            }
            
            if(node->right) {
                q.push({node->right, level + 1});
            }
        }
        
        for(auto &[level, value] : mp) {
            ans.push_back(value);
        }
        
        return ans;
    }
};