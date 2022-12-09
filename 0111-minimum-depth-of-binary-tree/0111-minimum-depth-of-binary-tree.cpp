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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        
        int ans = 0;
        if(leftDepth == 0 or rightDepth == 0) ans = leftDepth + rightDepth + 1;
        else ans = min(leftDepth, rightDepth) + 1;
        
        return ans;
    }
};