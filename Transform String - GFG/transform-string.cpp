// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
     int transform (string A, string B)
     {
       //code here.
       int n = A.size();
       int m = B.size();
       
       if(n != m) return -1;
       
       int sum = 0;
       for(int i=0;i<n;i++) sum += A[i] - B[i];
       
       if(sum !=0 ) return -1;
       
       int i = n-1;
       int j = m-1;
       while(i >= 0 and j >= 0)
       {
           if(A[i] == B[j]) j--;
           i--;
       }
       return j+1;
   }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends