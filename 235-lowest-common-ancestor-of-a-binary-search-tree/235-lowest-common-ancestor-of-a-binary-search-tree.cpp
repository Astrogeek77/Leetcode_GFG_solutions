/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        TreeNode* lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q)
        {
            if (node == NULL || node->val == p->val || node->val == q->val)
                return node;

            if (node->val > p->val and node->val > q->val)
                return lowestCommonAncestor(node->left, p, q);

            if (node->val < p->val and node->val < q->val)
                return lowestCommonAncestor(node->right, p, q);

            return node;
        }
};