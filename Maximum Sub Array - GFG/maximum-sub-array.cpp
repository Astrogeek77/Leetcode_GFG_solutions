//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    vector<int> ans, tempv;
	    ans.clear();
	    tempv.clear();
	    int big = 0, temp = 0;
	    for(int i = 0;i<n;i++)
	    {
	        if(a[i] < 0)
	        {
	            if(temp > big)
	            {
	                big = temp;
	                ans = tempv;
	                tempv.clear();
	                temp = 0;
	            }
	            else
	            {
	                temp = 0;
	                tempv.clear();
	            }
	        }
	        else
	        {
	            temp = temp + a[i];
	            tempv.push_back(a[i]);
	        }
	    }
	    if(temp > big)
	    {
	        ans = tempv;
	    }
	    if(ans.size() == 0) return {-1};
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends