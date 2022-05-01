// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool checkPrime(int n){
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0) return false;
        }
        return true;
    }
	
	int superPrimes(int n)
	{
	   int count = 0;
	   for(int i = 5; i <= n; i++){
	       if(checkPrime(i) and checkPrime(i-2))
	            count++;
	   }
	   return count;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends