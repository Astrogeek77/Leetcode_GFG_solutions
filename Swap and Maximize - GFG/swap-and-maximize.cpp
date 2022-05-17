// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
   sort(arr,arr+n);
   long long int ans=0;
   int i=0,j=n-1;
   vector<int>v;
   while(i<j)
   {
       v.push_back(arr[i]);
       v.push_back(arr[j]);
       i++;
       j--;
   }
   for(int i=0;i<v.size()-1;i++)  ans+=abs(v[i]-v[i+1]);
   ans+=abs(v[0]-v[v.size()-1]);
   return ans;
}