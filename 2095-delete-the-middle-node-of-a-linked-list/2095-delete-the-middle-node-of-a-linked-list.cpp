/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteMiddle(ListNode *head)
        {

            if (!head or !head->next) return NULL;
            
            ListNode *prev = NULL;
            
            ListNode *slowptr = head;
            ListNode *fastptr = head;

            while (fastptr and fastptr->next)
            {
                prev = slowptr;
                slowptr = slowptr->next;
                fastptr = fastptr->next->next;
            }

            prev->next = slowptr->next;
            delete slowptr;
            return head;
        }
};