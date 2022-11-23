//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define mod 1000000007
// #define mod 1e9+7
#define ll long long
class Solution{
public:
    int countBits(int N, long long int A[])
    {
        int m = 1000000007;
        int ans = 0;
        int mb = log2(*max_element(A, A+N));
        for(int i = 0; i <= mb; i++){
            ll cnt1 = 0;
            ll cnt0 = 0;
            for(int j = 0; j < N; j++)
            {
                // count on and off bits
                if(A[j] & (1 << i)) cnt0++;
                else cnt1++;
            }
            ans = (ans + cnt1 * cnt0 * 2) % mod;
            // ans %= m;
            // if(ans > m) ans -= m;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends