// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        if(m > n) swap(m, n);
        
        Node *prev = nullptr, *nxt = nullptr;
        Node *mptr = head, *nptr = head;
        
        for(int i = 0; i < m - 1; i++)  
        {
            prev = mptr;
            mptr = mptr -> next;
        } 
        
        for(int i = 0; i < n - 1; i++)  nptr = nptr -> next;
        
        nxt = nptr -> next;
        
        Node *p = nullptr, *curr = mptr;
        
        do {
            auto temp = curr;
            curr = curr -> next;
            temp -> next = p;
            p = temp;
        } while(p != nptr);
        
        mptr -> next = nxt;
        
        if(prev) 
        {
            prev -> next = p;
            return head;
        } else 
        {
            return p;
        }
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends