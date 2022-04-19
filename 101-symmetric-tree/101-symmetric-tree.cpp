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
    bool isSymmetric(TreeNode* root) {
       return isTreeSymetrical(root->left, root->right);
    }
    
    bool isTreeSymetrical(TreeNode *node1, TreeNode *node2)
    {
        //     Self Notes:
        // \U0001f4a1 Mirror property is    left == right and right == left
        // \U0001f4a1 pre-order traversal on root->left subtree, (root, left, right)
        // \U0001f4a1 modified pre-order traversal on root->right subtree, (root, right, left)
        // \U0001f4a1 compare the node val's if they are the same
        // \U0001f4a1 Do both traversals at the same time
        // \U0001f4a1 if left is null or right is null, then both sides must match and return true (base case)

        if (!node1)
            return !node2;
        if (!node2)
            return !node1;
        return (node1->val == node2->val) && (isTreeSymetrical(node1->left, node2->right)) && (isTreeSymetrical(node1->right, node2->left));
    }
};