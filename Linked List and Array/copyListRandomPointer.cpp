/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while(temp!=NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }
    }
    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while(temp!=NULL) {
            Node* copyNode = temp->next;
            if(temp->random) copyNode->random = temp->random->next;
            else copyNode ->random = nullptr;
            temp = temp->next->next;
        }
    }
    Node* getDeepCopyList(Node* head) {
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(temp!=NULL) {
            res->next = temp->next;
            res = res->next;
            temp ->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
        // Node* temp = head;
        // unordered_map<Node*, Node*> mpp;
        // while(temp!= NULL) {
        //     Node* newNode = new Node(temp->val);
        //     mpp[temp] = newNode;
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp!=NULL) {
        //     Node* copyNode = mpp[temp];
        //     copyNode->next = mpp[temp->next];
        //     copyNode->random = mpp[temp->random];
        //     temp = temp->next;
        // }
        // return mpp[head];
    }
};