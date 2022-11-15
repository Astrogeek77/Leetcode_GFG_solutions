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
// class Solution
// {
//     public:
//     void preorder(TreeNode *root, int &count)
//     {
//         if (!root) return;

//         count++;
//         preorder(root->left, count);
//         preorder(root->right, count);
//     }

//     int countNodes(TreeNode *root)
//     {
//         int count = 0;
//         preorder(root, count);
//         return count;
//     }
// };

class Solution
{
    public:
    int countNodes(TreeNode *root)
    {
        if(!root) return 0;
        // left and right heights
        int leftH = 0, rightH = 0;
        // left and right nodes
        TreeNode *leftN = root, *rightN = root;
        
        // traverse through left
        while(leftN)
        {
            leftH++;
            leftN = leftN->left;
        }     
        
        // traverse through right
        while(rightN)
        {
            rightH++;
            rightN = rightN->right;
        }   
        
        // use complete binary tree property for evry complete node
        if(leftH == rightH) return pow(2, leftH) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};