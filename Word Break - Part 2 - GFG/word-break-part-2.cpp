// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<string> ans;
    unordered_map<string,bool>mp;
    void helper(string so_far,string s,int i,string sub_s)
    {
        if(i>=s.length())
        {
            if(sub_s=="") ans.push_back(so_far);
            return;
        }
            
        sub_s+=s[i];
        if(mp[sub_s])
        {
            if(so_far!="") helper(so_far+" "+sub_s,s,i+1,"");
            else helper(sub_s,s,i+1,"");
        }
        helper(so_far,s,i+1,sub_s);
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        mp.clear();
        for(auto s : dict) mp[s]=true;
        
        ans.clear();
        helper("",s,0,"");
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends