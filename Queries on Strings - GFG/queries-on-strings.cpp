// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
		vector<int>SolveQueris(string str, vector<vector<int>>Query){
    	    vector<vector<int>> v(26);
    	    for(int i=0; str[i]!='\0'; i++)
    	    {
    	        v[str[i]-'a'].emplace_back(i+1);
    	    }
    	    vector<int> ans;
    	    for(auto it : Query)
    	    {
    	        int c=0;
    	        for(int i=0;i<26;i++)
    	        {
    	            for(auto x : v[i])
    	            {
    	                if(x>=it[0] && x<=it[1])
    	                {
    	                    c++;
    	                    break;
    	                }
    	            }
    	        }
    	        ans.emplace_back(c);
    	    }
    	    return ans;
	    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends