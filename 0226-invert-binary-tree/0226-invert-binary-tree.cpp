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
    void swapLRNodes(TreeNode* node)
    {
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    public:
        TreeNode* invertTree(TreeNode* root) 
        {
            // base case
            if(!root) return nullptr;

            // left and right children
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);

            // swap the childs
            swapLRNodes(root);

            return root;
        }
};