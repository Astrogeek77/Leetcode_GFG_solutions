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
// class Solution {
// public:
//     int minDiffInBST(TreeNode* node) 
//     {
//         if(node == nullptr) return 0;
        
//         while(node->left->left != nullptr)
//         {
//             node = node->left;
//         }
        
//         return abs(node->val - node->left->val);
//     }
// };

class Solution 
{
    int mini = INT_MAX;
    TreeNode* prev;
    
    void inorder (TreeNode* node) 
    {
        if (node == nullptr) return;
        inorder(node->left);
        
        if(prev != nullptr) 
            mini = min(mini, node->val - prev->val);
        
        prev = node;
        inorder(node->right);
    }
    
public:
    int minDiffInBST(TreeNode* root) 
    {
        inorder(root);
        return mini;
    }
};