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
    vector<vector<int>> verticalTraversal(TreeNode* node) {
        if (node == NULL)
        return {};

    // using a map to get record
    map<int, map<int, multiset<int>>> nodes; // storing coordinates with the respective nodes

    // using a queue structure
    queue<pair<TreeNode*, pair<int, int>>> queue; // storing coordinates wih respective nodes in the queue

    queue.push({node, {0, 0}}); // doing a level order traversal

    while (!queue.empty())
    {
        auto it = queue.front();
        queue.pop();
        TreeNode *temp = it.first;
        int x = it.second.first;
        int y = it.second.second;
        nodes[x][y].insert(temp->val);
        if (temp->left)
        {
            // when going to left child we go a step back horizontally and one step forward vertically
            queue.push({temp->left, {x - 1, y + 1}});
        }
        if (temp->right)
        {
            // when going to right child we go a step forward horizontally and one step forward vertically
            queue.push({temp->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
       ans.push_back(col);
    }
        return ans;
    }
};