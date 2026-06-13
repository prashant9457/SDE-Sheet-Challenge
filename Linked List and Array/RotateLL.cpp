/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
       
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int len = 1;
        ListNode* temp = head;

        //finding length
        while(temp->next!=NULL) {
            len++;
            temp = temp->next;
        }
        //index i want to break from
        ListNode* last = temp;
        
        int gotoIndex = len - (k)%len;

        if(k%len == 0) return head; 

        temp = head;
        ListNode* prev = NULL;
        //reach the index
        while(gotoIndex--) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        last->next = head;

        return temp;
    }
};