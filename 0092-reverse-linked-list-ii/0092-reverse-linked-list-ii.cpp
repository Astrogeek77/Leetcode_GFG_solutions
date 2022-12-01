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
    ListNode* reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0), *pre = dummy, *curr;
        dummy->next = head;

        int ind = 0;
        for(int i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }
        curr = pre->next;

        for(int i = 0; i < right - left; i++)
        {
            ListNode *nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = pre->next;
            pre->next = nextNode;
        }
        return dummy->next;
    }
};