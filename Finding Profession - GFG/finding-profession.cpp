// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

//solution is really simple 
//if position is left or odd that means the output is same as its parent 
//otherwise it is opposite 
//and base condition would be pos==1 or level==1 what could be the output 

//here position of the parent of x would be like this pos(parx)=(pos(x)+1)/2 it is like this because parent of any node in BT

class Solution{
public:
    char profession(int level, int pos)
    {
        if(level==1||pos==1)
            return 'e';
        char parent = profession(level-1,(pos+1)/2);   
        if(pos&1)
            return parent;
        else
            return parent=='e'?'d':'e';
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int level, pos;
        cin>>level>>pos;
        
        Solution ob;
        if(ob.profession(level, pos) == 'd')
            cout<<"Doctor\n";
        else
            cout<<"Engineer\n";
    }
    return 0;
}  // } Driver Code Ends