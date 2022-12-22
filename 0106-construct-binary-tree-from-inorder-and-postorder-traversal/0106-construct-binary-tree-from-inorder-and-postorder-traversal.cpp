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
   
    TreeNode* build(vector<int> &inorder, vector<int> &postorder, int &index, int inOrderStart, int inOrderEnd, int n, map< int, int> &nodeToIndex)
    {
       	//base case;
        if (index < 0 || inOrderStart > inOrderEnd) return NULL;

        int element = postorder[index--];
        TreeNode *root = new TreeNode(element);
        int position = nodeToIndex[element];

        root->right = build(inorder, postorder, index, position + 1, inOrderEnd, n, nodeToIndex);
        root->left = build(inorder, postorder, index, inOrderStart, position - 1, n, nodeToIndex);
        
        return root;
    }
    
    public:
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        int postOrderIndex = n - 1;

        map<int, int> nodeToIndex;
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }

        TreeNode *ans = build(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
        return ans;
    }
};