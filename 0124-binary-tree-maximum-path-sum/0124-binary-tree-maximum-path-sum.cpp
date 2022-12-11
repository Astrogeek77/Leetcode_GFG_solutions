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
    int ans = INT_MIN;
    int helper(TreeNode *node)
    {
        if (node == nullptr) return 0;
        
        int leftTreeSum = max(0, helper(node->left));
        int rightTreeSum = max(0, helper(node->right));
        
        int curr = node->val + leftTreeSum + rightTreeSum;
        ans = max(ans, curr);
        
        return (node->val + max(leftTreeSum, rightTreeSum));
    }
    public:
        int maxPathSum(TreeNode *root) 
        {
            helper(root);
            return ans;
        }
};