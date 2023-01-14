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
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            if (head == NULL) return head;
            
            // store the start of even linked list
            ListNode *evenHead = head->next, 
            *p1 = head, 
            *p2 = head->next;
            
            // p1 tracks the odd pos list
            // p2 tracks the even pos list
            while (p2 && p2->next)
            {
                p1->next = p1->next->next;
                p2->next = p2->next->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            // attach the even list at the end of odd list
            
            p1->next = evenHead;
            return head;
            
            // evenHead->next = p1;
            // return evenHead;
        }
};