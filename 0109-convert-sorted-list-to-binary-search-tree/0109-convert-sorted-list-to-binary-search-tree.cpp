/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(int i, int j, vector<int> &nodes)
    {
        if(i > j) return nullptr;
        int mid = (i + j) / 2;
        
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = helper(i, mid - 1, nodes);
        root->right = helper(mid + 1, j, nodes);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* ListHead) 
    {
        vector<int> nodes;
        while(ListHead != nullptr)
        {
            nodes.push_back(ListHead->val);
            ListHead = ListHead->next;
        }
        int left = 0, right = nodes.size() - 1;
        TreeNode* TreeRoot = helper(left, right, nodes);
        return TreeRoot;
    }
};