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
private:  
    ListNode* reverse(ListNode* node)
    {
        if(!node or !node->next) return node;
        ListNode* head = reverse(node->next);
        node->next->next = node;
        node->next = NULL;
        return head;
    }
    
    ListNode* helper(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        
        int sum = l1->val + l2->val;
        ListNode* curr = new ListNode(1);
        
        if(sum > 9) curr = helper(curr, l1->next);
        else curr = l1->next;
        
        curr = helper(curr, l2->next);
        ListNode* head = new ListNode(sum % 10, curr);
        return head;
    }    
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverse(l1);
        ListNode* rl2 = reverse(l2);
        
        ListNode* head = helper(rl1, rl2);
        return reverse(head);
    }
};