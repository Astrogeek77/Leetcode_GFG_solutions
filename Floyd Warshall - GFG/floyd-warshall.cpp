//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&m)
	{
	    
	    int n = m.size();
	    
	    // if the edge does not exists between two nodes 
	    // make it 1e9 to ease the min operation
	    for(int i = 0;i < n; i++)
	    {
	        for(int j = 0;j < n; j++)
	        {
	            if(m[i][j] == -1) m[i][j] = 1e9;
	        }
	    }
	    
	    for(int via = 0; via < n; via++)
	    {
    	    for(int i = 0; i < n; i++)
    	    {
    	        for(int j = 0; j < n; j++)
    	        {
    	            m[i][j] = min(m[i][j], m[i][via] + m[via][j]);
    	        }
    	    }
	    }
	    
	    // CHECKING FOR NEGETIVE CYCLES
	   // for(int i=0;i<n;i++)
	   // {
	   //     if(matrix[i][i] < 0)cout<<"Negetive cycle exists !"<<endl;
	   // }
	    
	    // UNDO THE CHANGES DONE, CHANGE 1E9 TO -1 AGAIN
	    for(int i = 0;i < n; i++)
	    {
	        for(int j = 0;j < n; j++)
	        {
	            if(m[i][j] == 1e9) m[i][j] = -1;
	        }
	    }
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends