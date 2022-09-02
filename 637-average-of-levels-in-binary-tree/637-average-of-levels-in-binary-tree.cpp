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
        vector<pair<long, int>> count;	//  stores (sum of a level, no of elements in that level)
    void dfs(TreeNode *root, int depth)
    {
        if (!root) return;
        int a = root->val;
        if (count.size() <= depth)
        {
        	// to check if we have any entry corresponding to current depth 
            count.push_back({ a,
                1 });	//  if  we are at depth 1 and only depth 0 is completed then count.size()=1
        }
        else
        {
            count[depth].first += a;
            count[depth].second++;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        count.clear();
        dfs(root, 0);
        vector<double> ans;
        for (int i = 0; i < count.size(); i++)
        {
            ans.push_back((double) count[i].first / count[i].second);	// pushing in averages
        }
        return ans;
    }
};