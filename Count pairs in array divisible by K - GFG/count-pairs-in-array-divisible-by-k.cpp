// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int k) 
    {
        map<long long, long long> mp;
        for(int i = 0; i < n; i++)
            mp[A[i] % k] += 1;
            
        long long ans = 0;
        for(int i = 1; i < k; i++) 
        {
            if(i != (k - i))
                ans += mp[i] * mp[k - i];
            else
                ans += (mp[i] * (mp[i] - 1));
        }
        ans /= 2;
        ans += (mp[0] * (mp[0] - 1)) / 2;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends