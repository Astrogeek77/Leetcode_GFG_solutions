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
    ListNode* reverse(ListNode* head){ // reverse list
        if(!head or !head->next) return head;
        
        auto nextNode = head->next;
        ListNode* newHead = reverse(nextNode);
        nextNode->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto revHead = head, temp = head;
        int p = 1; // counter to reach kth node
        
        while(temp and p < k){ // traverse to the kth node
            temp =  temp->next;
            p++;
        }
        
        if(p == k and temp){
            auto i = temp->next; // next node after kth
            temp->next = NULL;
            auto j = revHead; // get old Head
            revHead = reverse(revHead); // reverse k nodes
            j->next = reverseKGroup(i, k); // connect to next k reversed nodes.
        }
        return revHead; // return the new Head
    }
};