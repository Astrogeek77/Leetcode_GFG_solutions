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
        bool hasCycle(ListNode *head)
        {
            unordered_set<ListNode*> set;

            ListNode *curr = head;

            while (curr)
            {
                if (set.find(curr) == set.end())
                {
                    set.insert(curr);
                    curr = curr->next;
                }
                else
                {
                    return true;
                    break;
                }
            }
            return false;
        }
};