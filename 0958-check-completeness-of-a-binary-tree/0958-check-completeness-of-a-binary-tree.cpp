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
        bool isCompleteTree(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            
            int i = 0, flag = 0;
            while (!q.empty())
            {
                TreeNode* node = q.front();
                q.pop();
                
                if (flag == true && node != nullptr) return false;
                if (node == nullptr)
                {
                    flag = 1;
                    continue;
                }
                q.push(node->left);
                q.push(node->right);
            }
            return true;
        }
};