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
    void solve(TreeNode *root, string ans, string &maxi)
    {
        if (root == NULL) return;

        // convert the num to char
        ans.push_back((char)(root->val + 'a'));

        // once a leaf node is reached then
        if (root->left == NULL && root->right == NULL)
        {
            string str = ans;
            // reverse the string because we want the path from leaf to root.
            reverse(str.begin(), str.end());

            // return lexographically smaller string
            if (maxi == "" or str < maxi) maxi = str;
        }
        
        // go towards left
        solve(root->left, ans, maxi);
        // then right
        solve(root->right, ans, maxi);
        
        // pop_back to explore multiple paths from a particular root.
        ans.pop_back();
    }

    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "", maxi = "";
        solve(root, ans, maxi);
        return maxi;
    }
};