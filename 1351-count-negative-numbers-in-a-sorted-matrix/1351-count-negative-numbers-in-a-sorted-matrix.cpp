class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       
        int m=grid[0].size();
        int n=grid.size();
        int count=0;
        int i=0;
        int j=m-1;
        
        if(grid[n-1][m-1]>0) 
            return 0;
        while(i<n && j>=0)
        {
            if(grid[i][j]<0) 
            {
               count+=n-i;
               j--;
            }
            else
            {
                i++;
            }
        }
        
        return count;
    }
};