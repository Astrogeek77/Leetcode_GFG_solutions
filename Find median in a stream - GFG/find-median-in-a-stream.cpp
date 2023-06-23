//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    priority_queue <int> mx;
    priority_queue <int, vector<int> , greater<int>> mn;
    bool b = true;
    void insertHeap(int &x)
    {
        if(b)
        {
            mn.push(x);
            mx.push(mn.top());
            mn.pop();
        }
        else
        {
            mx.push(x);
            mn.push(mx.top());
            mx.pop();
        }
        b = !b;
    }
    void balanceHeaps(){
    }
    double getMedian(){
        return b ? double(mn.top()+mx.top())/2 : mx.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends