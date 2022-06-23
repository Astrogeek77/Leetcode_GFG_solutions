// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int solve(long long int n,vector<long long int> &t){
        if(n == 1)
           return 2;
        if(n == 2)
           return 3;
           
        if(t[n] != -1)
           return t[n];
           
        return t[n] = (solve(n-1,t) + solve(n-2,t))%1000000007;
    }
    
    int TotalWays(int N)
    {
        vector<long long int> t(N+1,-1);
        long long int temp = solve(N,t);
        return ((temp*temp)%(1000000007));
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends