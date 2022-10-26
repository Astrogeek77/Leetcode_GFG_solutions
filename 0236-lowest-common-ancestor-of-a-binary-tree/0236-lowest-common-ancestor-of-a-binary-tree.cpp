/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        TreeNode* lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q)
        {
           	// Brute force solution here is print the path for the two nodes and compare the paths.
           	// return the last node, after which the paths become different.

           	// assuming that val1 and val2 exist in the tree
            if (node == NULL || node->val == p->val || node->val == q->val)
                return node;

            TreeNode *left = lowestCommonAncestor(node->left, p, q);
            TreeNode *right = lowestCommonAncestor(node->right, p, q);

            if (left && right) return node;

            return (left != NULL ? left : right);
        }
};