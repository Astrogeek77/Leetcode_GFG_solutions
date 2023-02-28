/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:

        string traverse(TreeNode *node, unordered_map<string, int> &freq, vector<TreeNode*> &res)
        {
            if (node == nullptr)
            {
                return "#";
            }
            string subtree = traverse(node->left, freq, res) + "," + traverse(node->right, freq, res) + "," + to_string(node->val);

            freq[subtree]++;
            if (freq[subtree] == 2)
            {
                res.push_back(node);
            }
            return subtree;
        }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> freq;
        vector<TreeNode*> res;
        traverse(root, freq, res);
        return res;
    }
};