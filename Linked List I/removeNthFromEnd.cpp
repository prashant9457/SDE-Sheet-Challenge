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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        ListNode* temp = head; //use for finding length

        while(temp != NULL) {temp = temp->next; len++;}

        int gotoIndex = len - n ; //index of node from start
       
        temp = head;
        ListNode* prev = NULL;

        if(gotoIndex == 0) return head->next;
        
        while(gotoIndex && temp->next != NULL) 
        {
            prev = temp;
            temp = temp->next;
            gotoIndex--;
        }


        if(prev == NULL) return NULL; 
        prev->next = temp->next;

        return head;
    }
};