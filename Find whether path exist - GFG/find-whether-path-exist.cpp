// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
    public:
    bool solve(vector<vector<int>> &grid, int x, int y) {
        // Edge Case
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid.size() || !grid[x][y]) return false;
        // Base Case
        if(grid[x][y] == 2) return true;
        
        grid[x][y] = 0;
        return solve(grid, x+1, y) || solve(grid, x, y+1) || 
               solve(grid, x-1, y) || solve(grid, x, y-1);
    }
    bool is_Possible(vector<vector<int>>& grid) {
        int x, y;
        for(x = 0; x < grid.size(); x++) 
            for(y = 0; y < grid.size(); y++) 
                if(grid[x][y] == 1) return solve(grid, x, y);
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends