/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */
class Solution {
    public:
    Node* mergeTwoLists(Node* head1, Node* head2) {
        if (head1 == NULL)
            return head2;
    
        if (head2 == NULL)
            return head1;
    
        Node* result;
        
        if (head1->data < head2->data) {
            result = head1;
            result->bottom = mergeTwoLists(head1->bottom, head2); 
        } else {
            result = head2;
            result->bottom = mergeTwoLists(head1, head2->bottom); 
        }
    
        return result;
    }
    
    Node *flatten(Node *head) {
        if(!head)
            return head;
    
        Node* temp = flatten(head->next);
        
        return mergeTwoLists(head, temp);
    }
};

