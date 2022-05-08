/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
        {
           	// ListNode *curr2 = headB;

            while (headB)
            {
                ListNode *curr1 = headA;
                while (curr1)
                {
                    if (curr1 == headB) return headB;
                    curr1 = curr1->next;
                }
                headB = headB->next;
            }
            return NULL;
        }
};