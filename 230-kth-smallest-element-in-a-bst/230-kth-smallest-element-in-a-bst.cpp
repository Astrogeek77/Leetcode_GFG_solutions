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
    int countNodes(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int kthSmallest(TreeNode* node, int k) {
        
    if (node == NULL)
        return 0;
    if (k < 0 or k > countNodes(node))
        return -1;

    int count = 0;
    int ans = -1;

    // Morris Inorder
    TreeNode *curr = node;
    while (curr)
    {
        if (!curr->left)
        {
            count++;
            if (count == k) ans = curr->val;
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                if (count == k)
                    ans = curr->val;
                curr = curr->right;
            }
        }
    }
    return ans;
    }
};