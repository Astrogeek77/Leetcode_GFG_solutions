// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
      vector<int> numAndDen(int n, int d) 
      {
        int num = -1, den = 1;
        for(int y = d+1; y <= 1e4; y++) 
        {
            int x = (n*y)/d;
             if(__gcd(x,y) == 1) 
             {
                if(1.0*x/y > 1.0*num/den)
                    num=x, den=y;
            }
        }
        return {num, den};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends