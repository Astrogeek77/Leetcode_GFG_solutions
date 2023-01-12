 /*
 Definition
 for a binary tree node.*struct TreeNode
 {
     *int val;
     *TreeNode * left;
     *TreeNode * right;
     *TreeNode(int x): val(x), left(NULL), right(NULL) {}
         *
 };
 */
 class Solution
 {
     vector<int> ans;
     unordered_map<TreeNode*, TreeNode*> par;
     unordered_set<TreeNode*> set;
     
     void markParent(TreeNode* node, TreeNode* parent)
     {
         if(!node) return;
         par[node] = parent;
         
         markParent(node->left, node);
         markParent(node->right, node);
     }
     
     void helper(TreeNode* target, int k, int dist)
     {
         // three directions possible from a node
         // left
         // right
         // parent
         
         if(!target or dist > k) 
             return;
         if(k == dist)
             ans.push_back(target->val);
         
         set.insert(target);
         if(target->left != nullptr and set.find(target->left) == set.end())
             helper(target->left, k, dist+1);
         
         if(target->right != nullptr and set.find(target->right) == set.end())
             helper(target->right, k, dist+1);
         
         if(par[target] != nullptr and set.find(par[target]) == set.end())
             helper(par[target], k, dist+1);
     }
     
     public:
     vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
     {
         if(!root) return {};
         markParent(root, nullptr);
         helper(target, k, 0);
         
         return ans;
     }
 };