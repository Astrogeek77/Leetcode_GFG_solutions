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
    int count; // result

    pair<int, int> helper(TreeNode *root)
    {
        if (!root) return { 0, 0 }; // edge case
        
        int sum = root->val; 
        int level = 1;

        if (root->left)
        {
            pair<int, int> it = helper(root->left);
            sum += it.first; // increase sum
            level += it.second; // increase lvl
        }

        if (root->right)
        {
            pair<int, int> it = helper(root->right);
            sum += it.first;  // increase sum
            level += it.second;  // increase lvl
        }

        if ((sum / level) == root->val) count++; // calc Avg
        return {
            sum,
            level
        };
    }

    int averageOfSubtree(TreeNode *root)
    {
        count = 0;
        helper(root);
        return count;
    }
};