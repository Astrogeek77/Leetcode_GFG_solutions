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
        ListNode *start = new ListNode();
        start->next = head;
        
        ListNode *one = start, *two = start;
        
        for(int i = 0; i < n; i++){
            one = one->next;
        }
        
        while(one->next != NULL){
            one = one->next;
            two = two->next;
        }
        
        two->next = two->next->next;
        return start->next;
    }
};