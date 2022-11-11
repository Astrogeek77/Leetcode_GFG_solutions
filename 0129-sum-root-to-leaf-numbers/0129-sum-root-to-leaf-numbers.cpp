/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    int sum = 0;
    void helper(TreeNode *root, int ans)
    {
        if (root == NULL) return;

        ans = ans * 10 + root->val;
        cout << ans << endl;

        if (root->left == NULL and root->right == NULL)
        {
            sum += ans;
            return;
        }

        helper(root->left, ans);
        helper(root->right, ans);
    }
    public:
        int sumNumbers(TreeNode *root)
        {
            int ans = 0;
            helper(root, ans);
            return sum;
        }
};