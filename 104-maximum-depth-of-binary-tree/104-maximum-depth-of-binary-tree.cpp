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
        int maxDepth(TreeNode *root)
        {
           	//         https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/1770060/C%2B%2B-oror-Recursive-oror-DFS-oror-Example-Dry-Run-oror-Well-Explained

            if (!root) return 0;
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            return max(left, right) + 1;
        }
};