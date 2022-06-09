// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
 public:
   int find_par(int val,int par[])
   {
       while(par[val]!=val)
       val=par[val];
       return val;
   }
   void union_( int a, int b, int par[], int rank[]) 
   {
       int p1=find_par(a,par);
       int p2=find_par(b,par);
       if(rank[p1]<rank[p2])
       par[p1]=p2;
       else if(rank[p1]>rank[p2])
       par[p2]=p1;
       else par[p1]=p2;
       rank[p2]++;
   }
   
   //Function to check whether 2 nodes are connected or not.
   bool isConnected(int x,int y, int par[], int rank1[])
   {
       return(find_par(x,par)==find_par(y,par));
   }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends