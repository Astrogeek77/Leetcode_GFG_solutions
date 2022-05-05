// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int num(string n)
    { 
       return stoi(n);
    }
    
    string stringPartition(string S, int a, int b)
    {
     for(int i =  0; i < S.length() - 1; i++)
     {
       if(num(S.substr(0, i+1)) %a == 0 && num(S.substr(i+1)) % b == 0)
            return (S.substr(0,i+1)+" "+ S.substr(i+1));
     }
     return "-1";
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends