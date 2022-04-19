class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

private:
    void inorder(TreeNode *root)
    {
        if(root == NULL) return;
        inorder(root->left);
        
        if(prev != NULL && (root->val < prev->val)){
            if(first == NULL) // First Violation
            {
                first = prev;
                middle = root;
            } 
            else last = root;  // Second Violation
        }
        
        prev = root; // set prev to previous node
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
       first = middle = last = NULL;
       prev = new TreeNode(INT_MIN);
        
       inorder(root);
        
       if(first && last) swap(first->val, last->val);
       else if(first && middle) swap(first->val, middle->val);
    }
};