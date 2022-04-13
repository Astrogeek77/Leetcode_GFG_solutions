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
    TreeNode *ROOT;
    bool find(int val) {
        TreeNode *temp = ROOT;
        while(temp) {
            if (temp->val == val) return true;
            else if (temp->val > val) temp = temp->left;
            else temp = temp->right; 
        }
        return false;
    }

    bool util(TreeNode *root, int k) {
        if (!root) {
            return false;
        }

        if (root->val != k / 2 && find(k - root->val)) return true;
        return util(root->left, k) || util(root->right, k); 
    }

    bool findTarget(TreeNode* root, int k) {
        this->ROOT = root;
        return util(ROOT, k);
    }
};