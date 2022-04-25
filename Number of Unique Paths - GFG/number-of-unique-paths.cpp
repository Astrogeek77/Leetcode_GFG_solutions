// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        vector<int> prev(n, 0);
	
    	prev[0] = 1;
    	for(int i = 0; i < m; i++){
    		vector<int> temp(n, 0);
    		for(int j = 0; j < n; j++){
    			if(i == 0 and j == 0) {
    				temp[j] = 1;
    				continue;
    			}	
    			int up = 0, left = 0;
    			if(i>0) up = prev[j];
    			if(j>0) left = temp[j - 1];
    			temp[j] = up + left;
    		}
    		prev = temp;
    	}
    	return prev[n-1];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends