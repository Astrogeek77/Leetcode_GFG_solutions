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
    // Level order traversal from bottom-up
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector < int>> answer;
        if (!root) return answer;
        queue<TreeNode*> q;	
        q.push(root);	
        while (!q.empty())	
        {
            int size = q.size(); //storing queue size for inside loop
            vector<int> row;	// nodes in a level
            while (size--)
            {
                TreeNode *curr = q.front();
                q.pop();

                row.push_back(curr->val);	

                if (curr->left) q.push(curr->left);	
                if (curr->right) q.push(curr->right);	
            }
            answer.push_back(row);	
        }
        // print2dVector(answer);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};