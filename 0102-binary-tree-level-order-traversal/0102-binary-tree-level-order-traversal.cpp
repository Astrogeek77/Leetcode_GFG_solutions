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
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         vector<vector < int>> answer;
//         if (!root) return answer;
//         queue<TreeNode*> q;	
//         q.push(root);	
//         while (!q.empty())	
//         {
//             int size = q.size(); //storing queue size for inside loop
//             vector<int> row;	// nodes in a level
//             while (size--)
//             {
//                 TreeNode *curr = q.front();
//                 q.pop();

//                 row.push_back(curr->val);	

//                 if (curr->left) q.push(curr->left);	
//                 if (curr->right) q.push(curr->right);	
//             }
//             answer.push_back(row);	
//         }
//         return answer;
//     }
    
    vector<vector<int>> ans;
    void helper(TreeNode* node, int level = 0)
    {
        if(node == nullptr) return;
        if(level == ans.size()) ans.push_back(vector<int> ());
        
        ans[level].push_back(node->val);
        
        helper(node->left, level + 1);
        helper(node->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        helper(root);
        return ans;
    }
};