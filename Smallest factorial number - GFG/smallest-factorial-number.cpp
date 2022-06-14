// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    bool helper(int mid, int n){
        int mul = 5;
        int count = 0;
        
        while(mul <= mid){
            count += (mid / mul);
            mul = mul * 5;
        }
        
        return (count >= n);
    }
    public:
        int findNum(int n)
        {
            if(n == 1) return 5;
            int lo = 0, hi = 5 * n;
            
            // Binary Search
            while(lo < hi){
                int mid = lo + (hi - lo) / 2;
                
                if(helper(mid, n)) hi = mid;
                else lo = mid + 1;
            }
            return lo;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends