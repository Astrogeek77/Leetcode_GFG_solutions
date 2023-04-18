//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int tar, ans;
    // size, max on the left, min on the right, sum of the subtree
    vector<int> solve(Node *root)
    {
        // null
        if (!root)
            return {0, INT_MIN, INT_MAX, 0};

        // leaf
        if (!root->left and !root->right)
        {
            if (root->data == tar)
                ans = min(ans, 1);
            return {1, root->data, root->data, root->data};
        }

        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);

        // check if bst
        if (l[1] < root->data && root->data < r[2])
        {
            if ((root->data + l[3] + r[3]) == tar)
                ans = min(ans, 1 + l[0] + r[0]);
            return {1 + l[0] + r[0], max(root->data, r[1]), min(root->data, l[2]), root->data + l[3] + r[3]};
        }

        return {min(l[0], r[0]), INT_MAX, INT_MIN, root->data + l[3] + r[3]};
    }

    int minSubtreeSumBST(int target, Node *root)
    {
        tar = target, ans = 1e9;
        solve(root);
        return ans == 1e9 ? -1 : ans;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends