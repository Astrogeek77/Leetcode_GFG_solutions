/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode(int x) : val(x), next(NULL) {}
 *};
 */
// class Solution
// {
//     public:
//         ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
//         {
//            	// ListNode *curr2 = headB;

//             while (headB)
//             {
//                 ListNode *curr1 = headA;
//                 while (curr1)
//                 {
//                     if (curr1 == headB) return headB;
//                     curr1 = curr1->next;
//                 }
//                 headB = headB->next;
//             }
//             return NULL;
//         }
// };

class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *head1, ListNode *head2)
        {
            ListNode *curr1 = head1;
            ListNode *curr2 = head2;

            while (curr1 != curr2)
            {
                curr1 = curr1 == NULL ? head2 : curr1->next;
                curr2 = curr2 == NULL ? head1 : curr2->next;
            }

            return curr1;
        }
};