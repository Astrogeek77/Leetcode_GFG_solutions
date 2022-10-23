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
    TreeNode* constructTree1(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map< int, int> &map)
    {
        if (preStart > preEnd or inStart > inEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);	// get root
        int inRoot = map[root->val];	// get position of root in inorder
        int numsLeft = inRoot - inStart;	// the count of nums on the left of inroot

        root->left = constructTree1(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, map);
        root->right = constructTree1(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, map);
        return root;
    }

   TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
       	//? preorder =[3,9,20,15,7], inorder =[9,3,15,20,7]
        map<int, int> map;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;	// mapping the index of inorder

        TreeNode* root = constructTree1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, map);
        return root;
    }
};