// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool dfs(vector<vector<int>>&sol,vector<vector<int>>&matrix,int n,int i,int j)
    {
       if(i>=n||j>=n) return 0;
       sol[i][j]=1;
       if(i==n-1 && j==n-1) return 1;
       
       int val=matrix[i][j];
       for(int k=1;k<=val;k++)
       {
           if(dfs(sol,matrix,n,i,j+k)||dfs(sol,matrix,n,i+k,j))
           return 1;
       }
       sol[i][j]=0;
       return 0;
    }
    vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
       // Code here
       int n=matrix.size();
       vector<vector<int>>sol(n,vector<int>(n,0));
       if(dfs(sol,matrix,n,0,0))
       return sol;
       return {{-1}};
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends