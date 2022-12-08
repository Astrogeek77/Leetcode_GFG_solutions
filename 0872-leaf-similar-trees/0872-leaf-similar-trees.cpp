/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    vector<int> v[2];
    int i = 0;
    void helper(TreeNode *root, int i)
    {
       	// base condition
        if (root == NULL) return;

       	// leaf node
        if (root->left == NULL && root->right == NULL)
            v[i].push_back(root->val);
            
        helper(root->left, i);
        helper(root->right, i);
        return;
    }
    public:
        bool leafSimilar(TreeNode *root1, TreeNode *root2)
        {
            helper(root1, 0);
            helper(root2, 1);
            if (v[0].size() != v[1].size())
                return false;
            int size = v[0].size();
            for (i = 0; i < size; i++)
            {
                if (v[0][i] != v[1][i])
                    break;
            }
            return i == size;
        }
};