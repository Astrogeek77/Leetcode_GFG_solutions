// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool isPossible(long N, long M, long L, long H[], long A[], long h) {

        long tot = 0;
        for(int i=0; i < N; i++) {
            /// speed of Ith biker at hour h
            long speed = H[i] + A[i] * h - 1;
            if(speed >= L) tot += speed;
            if(tot >= M) return true;
        }
        
        return false;
    }
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        long left = 1, right = 1e11;
        
        long ans = 0;
        while(left <= right) {
            long mid = left  + (right - left)/2;
            
            if(isPossible(N, M, L, H, A, mid)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends