// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
      unordered_map<char,int>mp;
       int i=0,j=0, n=str.size(),ans=INT_MAX,curr;
       unordered_set<char>st; // to calculate total no ,of elements..
       for(int i=0;i<n;i++){
           st.insert(str[i]);
       }
       int sz=st.size();
        for(int i=0;i<n;i++){
            mp[str[i]]++;
            while(mp[str[j]]>1){
                mp[str[j]]--;
                j++;
            }
            if(mp.size()==sz){
                 curr=i-j+1;
                ans=min(ans,curr);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends