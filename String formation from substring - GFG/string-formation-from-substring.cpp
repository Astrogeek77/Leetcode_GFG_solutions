// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    int len = s.size();
	    queue<char> q;
	    q.push(s[0]);
	    
	    for(int i = 1; i < len; i++){
	        if(q.front() == s[i]) q.pop();
	        q.push(s[i]);
	    }
	    
	    if(q.size() == len) return 0;
	    
	    for(int i = 0; i < len; i++){
	        if(q.front() != s[i]) return 0;
	        q.pop();
	        q.push(s[i]);
	    }
	    return 1;
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
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends