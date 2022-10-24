/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool s(ListNode *h, TreeNode *r)
        {
            if (!h) return 1;
            if (!r) return 0;
            if (r->val == h->val) return s(h->next, r->left) || s(h->next, r->right);
            return 0;
        }

    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!root) return 0;
        if (s(head, root)) return 1;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};