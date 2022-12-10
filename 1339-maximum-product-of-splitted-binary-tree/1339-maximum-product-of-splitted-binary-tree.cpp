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
    long ans = 0, totalSum = 0, mod = 1e9 + 7;
    int helper(TreeNode *root)
    {
        if (!root) return 0;
        
        int subtreeSum = helper(root->left) + helper(root->right) + root->val;
        ans = max(ans, (totalSum - subtreeSum) * subtreeSum);
        
        return subtreeSum;
    }
public:
    int maxProduct(TreeNode *root)
    {
        totalSum = helper(root);
        helper(root);
        return ans % mod;
    }
}; 