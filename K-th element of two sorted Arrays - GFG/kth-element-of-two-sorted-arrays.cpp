// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ans = 0, i = 0, j = 0, count = 0, check = -1, last = 0;
    
        while ((i < n) && (j < m))
        {
            if (arr1[i] <= arr2[j])
            {
                last = arr1[i];
                i++;
                count++;
            }
            else
            {
                last = arr2[j];
                j++;
                count++;
            }
            if (count == k)
                return last;
        }
        if (i == n)
            return arr2[j + k - count - 1];
        else
            return arr1[i + k - count - 1];
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends