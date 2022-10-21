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
        ListNode* swapList(ListNode *head)
        {
            if (!head or !head->next or !head->next->next) return head;

            ListNode *dummy = head;
            ListNode *curr = head;
            ListNode *prev = head;

            while (curr->next)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = NULL;
            curr->next = dummy->next;
            dummy->next = curr;
            
            dummy = dummy->next->next;

            swapList(dummy);
            return head;
        }
    void reorderList(ListNode *head)
    {
        swapList(head);
    }
};