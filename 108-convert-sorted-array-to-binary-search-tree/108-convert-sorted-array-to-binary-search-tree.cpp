/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct_bst(vector<int>& nums, int left, int right)
    {
        if(left > right) return NULL;
        
        int mid = (left + right) / 2;
        int val = nums[mid];
        TreeNode* root = new TreeNode(val);
        
        root -> left = construct_bst(nums, left, mid - 1);
        root -> right = construct_bst(nums, mid + 1, right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return construct_bst(nums, 0, n - 1);
    }
};