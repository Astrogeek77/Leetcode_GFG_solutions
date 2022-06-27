// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
       // code here
       vector<int>list;
       int M=N;
       int c=0;
       int k=N;
       while(k!=0)
       {
           if((k&1)==0) M=(1<<c)|M;
           k=k>>1;
           c++;
       }
       list.push_back(M-N);
       list.push_back(M);
       return list;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends