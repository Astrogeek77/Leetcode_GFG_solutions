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
class Solution {
    public:
        TreeNode* invertTree(TreeNode* root) 
        {
            // base case
            if(!root) return nullptr;

            // left and right children
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);

            // swap the childs
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = temp;

            return root;
        }
};