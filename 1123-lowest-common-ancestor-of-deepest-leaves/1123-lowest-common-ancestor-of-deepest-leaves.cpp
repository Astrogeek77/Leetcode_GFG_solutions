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
    int getDepth(TreeNode *node)
    {
        if (node == NULL) return 0;
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
    
    public:
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        if (root == NULL) return NULL;
        
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        
        if (left == right) return root;
        else if (left > right) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }
};