// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        if(9*n < sum) return "-1"; // Edge case
        
        string ans=""; // result
        for(int i=0;i<n;i++)
            ans+='0';
            int i=0;
        while(sum>0)    {
            if(sum>=9){
                ans[i]='9';
                sum-=9;
            }else{
                ans[i]=sum+'0';
                sum=0;
            }
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends