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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        
        while(temp){
            temp = temp->next;
            len++;
        }
        
        return len;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        
        int len = getLength(head);
        k = k % len;
        
        if(k == 0) return head;
        
        int i = len - k;
        int j = 1;
        
        ListNode* curr = head;
        
        while(j < i) { // move curr to the point rotation is to occcur
            curr = curr->next;
            j++;
        }
        
        ListNode* nTail = curr;
        ListNode* nhead = curr->next;
        
        while(curr->next){ // traverse the second part of list (after K)
            curr = curr->next;
        }
        
        curr->next = head;
        nTail->next = NULL;
        return nhead;
    }
};