//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      int fun(int i, int j, int x, int y, vector<vector<int>> &grid)
   {
       queue<pair<pair<int,int>,int>> q;
       int n=grid.size();
       int m=grid[0].size();
       
       q.push({{ i, j }, 0 }); 
       grid[i][j]=0;
       
       while(!q.empty())
       {
           i = q.front().first.first;
           j = q.front().first.second;
           int c = q.front().second;
           
           if(i==x && j==y) return c;
           q.pop();
           
           if(i-1 >= 0 && grid[i-1][j])
           {
               q.push({ {i-1, j}, c+1 });
               grid[i-1][j] = 0;
           }
           
           if(j-1 >= 0 && grid[i][j-1])
           {
               q.push({ {i, j-1}, c+1 });
               grid[i][j-1] = 0;
           }
           if(i+1 < n && grid[i+1][j])
           {
               q.push({ {i+1, j}, c+1 });
               grid[i+1][j] = 0;
           }
           if(j+1<m && grid[i][j+1])
           {
               q.push({ {i, j+1}, c+1 });
               grid[i][j+1] = 0;
           }
       }
       return -1;
   }
   int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                    pair<int, int> destination) {
       // code here
       int i = source.first;
       int j = source.second;
       
       int x = destination.first;
       int y = destination.second;
       
       if(!grid[i][j] || !grid[x][y]) return -1;
       
       return fun(i,j,x,y,grid);
   }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends