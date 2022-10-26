/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Codec
{
    public:

       	// Encodes a tree to a single string.
        string serialize(TreeNode *node)
        {
            if (!node) return "";

            string result = "";
            queue<TreeNode*> queue;
            queue.push(node);

            while (!queue.empty())
            {
                auto curr = queue.front();
                queue.pop();

                if (curr == NULL) result.append("#,");
                else
                {
                    result.append(to_string(curr->val) + ",");
                    queue.push(curr->left);
                    queue.push(curr->right);
                }
            }
           	// cout << "Serialized Tree: " << result << endl;
            return result;
        }

   	// Decodes your encoded data to tree.
    TreeNode* deserialize(string s)
    {
        if (s.size() == 0) return NULL;

        stringstream ss(s);
        string str;
        getline(ss, str, ',');
        
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty())
        {
            TreeNode *node = queue.front();
            queue.pop();

            getline(ss, str, ',');
            if (str == "#")
            {
                node->left == NULL;
            }
            else
            {
                node->left = new TreeNode(stoi(str));
                queue.push(node->left);
            }

            getline(ss, str, ',');
            if (str == "#")
            {
                node->right == NULL;
            }
            else
            {
                node->right = new TreeNode(stoi(str));
                queue.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));