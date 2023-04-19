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
    vector<int> dfs(TreeNode* node) 
    {
        if (node == nullptr) 
        {
            return {-1, -1, -1};
        }
        
        vector<int> leftSubtree = dfs(node->left);
        vector<int> rightSubtree = dfs(node->right);
        
        int leftLength = leftSubtree[1] + 1;
        int rightLength = rightSubtree[0] + 1;
        int maxLen = max({leftLength, rightLength, leftSubtree[2], rightSubtree[2]});
        
        return {leftLength, rightLength, maxLen};
    }
public:
    int longestZigZag(TreeNode* root) {
        vector<int> res = dfs(root);
        return res[2];
    }
    
};