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
    bool isSymmetric(TreeNode* root) 
    {
       return isTreeSymetrical(root->left, root->right);
        
//         if(!root->left) return !root->right;
//         if(!root->right) return !root->left;
        
//         bool ans = root->left->val == root->right->val;
//         bool ans2 = isSymmetric(root->left->left, root->right->right);
//         bool ans3 = isSymmetric(root->left->right, root->right->left);
        
//         return ans and ans2 and ans3;
    }
    
    bool isTreeSymetrical(TreeNode *leftNode, TreeNode *rightNode)
    {
        if (leftNode == nullptr)
            return rightNode == nullptr;
        if (rightNode == nullptr)
            return leftNode == nullptr;
        
        bool ans = leftNode->val == rightNode->val;
        bool ans2 = isTreeSymetrical(leftNode->left, rightNode->right);
        bool ans3 = isTreeSymetrical(leftNode->right, rightNode->left);
        
        return ans and ans2 and ans3;
        
        // return (node1->val == node2->val) && (isTreeSymetrical(node1->left, node2->right)) && (isTreeSymetrical(node1->right, node2->left));
    }
};