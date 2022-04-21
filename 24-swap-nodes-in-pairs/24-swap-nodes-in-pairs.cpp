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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head; // Base Cases
        
        ListNode *newHead = swapPairs(head->next->next); // Get the new Head
        ListNode *temp = head;  
        ListNode *curr = temp->next;
        
        temp->next = newHead;
        curr->next = temp;
        newHead = curr;
        
        return newHead;
    }
};