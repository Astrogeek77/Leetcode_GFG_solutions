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
        ListNode* detectCycle(ListNode *head)
        {

            if (head == NULL) return NULL;
            ListNode *slowPtr = head;
            ListNode *fastPtr = head;
            ListNode *entry = head;

            while (fastPtr && fastPtr->next)
            {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;

                if (fastPtr == slowPtr)
                {
                	// we detected a cycle
                    while (slowPtr != entry)
                    {
                    	// now we find the beginning node of the cycle
                        entry = entry->next;
                        slowPtr = slowPtr->next;
                    }
                    return entry;	// found the beginning node of the cycle
                }
            }
            return NULL;	//no cycle found, hence return NULL
        }
};