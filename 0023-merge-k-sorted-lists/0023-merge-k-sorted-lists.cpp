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
        ListNode* mergeKLists(vector<ListNode*> &lists)
        {
            vector<int> nodes;
            for (int i = 0; i < lists.size(); i++)
            {
                // for all list nodes, push into nodes array.
                ListNode *temp = lists[i];
                while (temp != NULL)
                {
                    nodes.push_back(temp->val);
                    temp = temp->next;
                }
            }
            // sort the nodes array
            sort(nodes.begin(), nodes.end());
            
            for (int i = 0; i < nodes.size(); i++)
            {
               cout << nodes[i] << " ";
            }
            
            // we create a new list with nodes elements
            ListNode *ans = new ListNode(-1);
            ListNode *temp = ans;
            for (int i = 0; i < nodes.size(); i++)
            {
                temp->next = new ListNode(nodes[i]);
                temp = temp->next;
            }
            return ans->next;
        }
};