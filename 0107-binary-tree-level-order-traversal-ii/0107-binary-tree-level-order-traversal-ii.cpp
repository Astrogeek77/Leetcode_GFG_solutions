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
    // print level order traversal (recursively)
    vector<vector<int>> ans;
    void helper(TreeNode* node, int level = 0)
    {
        if(node == nullptr) return;
        if(level == ans.size()) ans.push_back(vector<int> ());

        ans[level].push_back(node->val);

        helper(node->left, level + 1);
        helper(node->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        helper(root);
        // print2dVector(ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};