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
       	//     ListNode* removeNthFromEnd(ListNode* head, int n) 
       	//     {
       	//         int len = 1;
       	//         ListNode* curr = head;

       	//         while(curr->next) 
       	//         {
       	//             len++;
       	//             curr = curr->next;
       	//         }

       	//         cout << "len: "  << len << endl;

       	//         int idx = len - n;

       	//         ListNode* prev = head;
       	//         curr = head;
       	//         while(idx > 0)
       	//         {
       	//             prev = curr;
       	//             curr = curr->next;
       	//         }

       	//         prev->next = curr->next;
       	//         return head;
       	//     }

        ListNode* removeNthFromEnd(ListNode *head, int n)
        {
            ListNode* dummy = new  ListNode(0);
            dummy->next = head;
            ListNode *left = dummy, *right = dummy;

            while (n > 0)
            {
                n--;
                left = left->next;
            }

            while (left->next)
            {
                left = left->next;
                right = right->next;
            }
            
            right->next = right->next->next;
            return dummy->next;
        }
};