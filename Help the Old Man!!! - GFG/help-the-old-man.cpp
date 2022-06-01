// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
       vector<pair<int,int>> ind;
       void TOH(int N,int strt,int goal,int mid)
       {
           if(N==0)return;
           TOH(N-1,strt,mid,goal);
           ind.push_back({strt,goal});
           TOH(N-1,mid,goal,strt);
       }
        vector<int> shiftPile(int N, int n){
            // code here
            TOH(N,1,3,2);
            vector<int> ans;
            ans.push_back(ind[n-1].first);
            ans.push_back(ind[n-1].second);
            return ans;
        }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends