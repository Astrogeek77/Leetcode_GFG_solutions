//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
       int s=str.size();
       stack<Node *> st;
       for(int i=0;i<str.size();i++)
       {
           if(str[i]!='(' && str[i]!=')')
           {
               int num=0;
               
               while(i<s && isdigit(str[i]))
               {
                   num= num*10 +int(str[i]-48);
                   i+=1;
               }
               Node *x = new Node(num);
               st.push(x);
               i--;
           }
           else if(str[i]==')')
           {
               
               Node *x= st.top();
               st.pop();
               Node *y= st.top();
               if(!(y->left))  y->left=x;
               else y->right=x;
           }
       }
       return st.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends