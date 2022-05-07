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
    ListNode* reverseList(ListNode* head) {
        ListNode *prevptr = NULL; // pointer for previous node
        ListNode *curr = head;    // pointer for current node
        ListNode *nextptr = NULL; // pointer for next node
        
        while(curr){
            nextptr = curr->next; // point next pointer to current's next
            curr->next = prevptr; // current's next to previous node
            
            prevptr = curr; // previous ptr to current
            curr = nextptr; // current to next
        }
        
        return prevptr; // new head
    }
};