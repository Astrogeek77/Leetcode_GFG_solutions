class Solution
{
    public:
        vector<vector < int>> levelOrder(TreeNode *root)
        {
            vector<vector < int>> res;
            if (!root) return res;
            queue<TreeNode*> q;
            vector<int> vec;
            q.push(root);
            q.push(NULL);
            while (!q.empty())
            {
                TreeNode *t = q.front();
                if (t != NULL)
                    vec.push_back(t->val);
                q.pop();
                if (t == NULL)
                {
                    res.push_back(vec);
                    vec = {};
                    if (!q.empty())
                        q.push(NULL);
                }
                else
                {
                    if (t->left)
                        q.push(t->left);
                    if (t->right)
                        q.push(t->right);
                }
            }
            return res;
        }
};