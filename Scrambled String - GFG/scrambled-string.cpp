//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution
{
    unordered_map<string, int> t;
    
	public:
	bool check(string s1, string s2)
	{
	    // base cases
		if (s1 == s2)
		{
			return true;
		}

		if (s1.size() <= 1)
		{
			return false;
		}

		int n = s1.size();
		bool flag = false;

		for (int i = 1; i <= n - 1; i++)
		{
			string key = s1 + "_" + s2;
			if (t.find(key) != t.end())
			{
				return t[key];
			}

			//condition 1
			if (check(s1.substr(0, i), s2.substr(0, i)) && check(s1.substr(i, n - i), s2.substr(i, n - i)))
			{
				flag = true;
				break;
			}

			//condition 2
			if (check(s1.substr(0, i), s2.substr(n - i, i)) && check(s1.substr(i, n - i), s2.substr(0, n - i)))
			{
				flag = true;
				break;
			}
		}

		string k = s1 + "_" + s2;
		t[k] = flag;

		return flag;
	}

	bool isScramble(string S1, string S2)
	{
		return check(S1, S2);
	}
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends