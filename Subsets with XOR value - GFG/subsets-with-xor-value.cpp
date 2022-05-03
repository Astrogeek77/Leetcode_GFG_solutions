// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
   int helper(vector<int> &arr , int N , int K){
       if(N == 0) return K == 0;
       
       int pick, npick;
       pick = helper(arr , N - 1 , K ^ arr[N - 1]); // pick
       npick = helper(arr , N - 1 , K); // not pick
       return pick + npick;
   }
   
   int subsetXOR(vector<int> &arr, int N, int K) 
   {
       return helper(arr , N , K);
   }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends