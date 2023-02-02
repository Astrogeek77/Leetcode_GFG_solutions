//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    //0->same dir
    //1->change dir and then update to 0
 
    void solve(vector<vector<int>> &grid,int x, int y,int &ansX,int &ansY,
        char dir)
    {
        int n= grid.size(), m= grid[0].size();
        
        if(x< 0){
            ansX = x+1;
            ansY= y;
            return;
        }
        else if(x==n ){
            ansX= x-1;
            ansY= y;
             return;
        }else if(y< 0){
            ansX= x;
            ansY= y+1;  
            return;
        }
        else if(y== m ){
            ansX= x;
            ansY= y-1;
            return;
            
        }
        
        if(grid[x][y] == 0){
            switch (dir){
                case 'R':
                    solve(grid,x,y+1,ansX,ansY, dir);
                    break;
                case 'L':
                    solve(grid,x,y-1,ansX,ansY, dir);
                    break;
                case 'U':
                    solve(grid,x-1,y,ansX,ansY, dir);
                    break;
                case 'D':
                    solve(grid,x+1,y,ansX,ansY, dir);
                    break;
            }
        }
        
        ///up, right, down, or left to the directions
        //right, down, left, and up 
    
        else{
            
            grid[x][y] = 0;
            
            switch (dir){
                case 'R':
                    solve(grid,x+1,y,ansX,ansY, 'D');
                    break;
                case 'L':
                    solve(grid,x-1,y,ansX,ansY, 'U');
                    break;
                case 'U':
                    solve(grid,x,y+1,ansX,ansY, 'R');
                    break;
                case 'D':
                    solve(grid,x,y-1,ansX,ansY, 'L');
                    break;
            }
        }
        
    }
    
    
    pair<int,int> endPoints(vector<vector<int>> matrix){
        
        int x= 0, y=0, ansX, ansY;
        char dir= 'R';
        
        solve(matrix,x,y,ansX,ansY, dir);

        pair<int,int> ans;
        
        ans.first = ansX;
        ans.second = ansY;
        
        return ans;
        
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends