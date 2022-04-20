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
class BSTIterator {
private: 
    bool isReverse = false; // to propagate towards back
    stack<TreeNode *> stack; // stack to do inorder
public:
    BSTIterator(TreeNode* root, bool reverse = false) { // Constructor
        isReverse = reverse; 
        pushAll(root);
    }
    
    int next() {  // return the next value
        auto temp = stack.top();
        stack.pop();
        if (!isReverse) pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() { // return if the stack empty or not
        return !stack.empty();
    }
    
    void pushAll(TreeNode *node) // push all nodes to the stack
    {
        while (node)
        {
            stack.push(node);
            if (!isReverse) node = node->left;
            else node = node->right;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */