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
    int ans = -1;
    // helper to perform dfs traversal
    void helper(TreeNode* node, int mx, int mn)
    {
        // base case
        if(node == nullptr) return;
        
        // update mx and mn values
        if(node->val > mx) mx = node->val;
        else if(node->val < mn) mn = node->val;
        
        cout<<node->val<<" "<<mx<<" "<<mn<<endl;
        
        // calc the absolute max diff possible for a node
        int diff = max(abs(mx - node->val), abs(node->val - mn));
        
        cout << diff << endl;
        // update ans
        if(diff > ans) ans = diff;
        
        // traverse left and right childs
        helper(node->left, mx, mn);
        helper(node->right, mx, mn);
    }
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        helper(root, root->val, root->val);
        return ans;
    }
};