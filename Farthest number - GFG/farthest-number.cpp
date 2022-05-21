// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{ 
 public:
       vector<int> farNumber(int N,vector<int> Arr){
       //code here
       vector<int> arr(N);
       arr[N-1] = Arr[N-1];
       for(int i=N-2;i>=0;i--)
       {
           arr[i] = min(Arr[i],arr[i+1]);
       }
      for(int i=0;i<N;i++)
      {
          int ans = -1;
          int low = i,high = N-1;
        
          while(low<=high)
          {
            int mid = (low+high)/2;
              if(arr[mid]<Arr[i])  
              {
                  ans = mid;
                  low = mid+1;
              }
              else
              {
                  high = mid-1;
              }
          }
         Arr[i] = ans;
      }
   return Arr;
       }
   };

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends