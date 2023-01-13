/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    bool res;
    int helper(TreeNode *root)
    {
        if (!root) return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        if (abs(left - right) > 1) res = false;

        return max(left, right) + 1;
    }

    public:
        bool isBalanced(TreeNode *root)
        {
            res = true;
            helper(root);
            return res;
        }
};