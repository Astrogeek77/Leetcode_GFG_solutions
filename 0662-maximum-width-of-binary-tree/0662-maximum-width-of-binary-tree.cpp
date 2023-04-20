class Solution
{
    public:
        int widthOfBinaryTree(TreeNode *node)
        {
            if (node == nullptr) 
                return 0;

            int ans = 1; // counting root
            queue<pair<TreeNode*, long long int>> q;
            q.push({ node, 0 });

            while (!q.empty())
            {
                int sz = q.size();
                int lpos = 0, rpos = 0;
                int l = 0;
                int mn = q.front().second;
                for (int i = 0; i < sz; i++)
                {
                    pair<TreeNode*, long long int> p = q.front();
                    q.pop();
                    
                    TreeNode *curr = p.first;
                    long long int k = p.second - mn;
                    
                   	// leftmost node
                    if (i == 0) 
                        lpos = k;
                    
                   	// rightmost node
                    if (i == sz - 1)
                        rpos = k;

                    if (curr->left) 
                        q.push({ curr->left, 2 * k + 1 });

                    if (curr->right) 
                        q.push({ curr->right, 2 * k + 2 });
                }
               	// To store maximum difference.
                ans = max(ans, rpos - lpos + 1);
            }
            return ans;
        }
};