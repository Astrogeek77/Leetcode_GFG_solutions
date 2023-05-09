class Solution
{
    public:
        vector<int> spiralOrder(vector<vector < int>> &matrix)
        {
            if (matrix.size() == 0) return {};
            
            int left = 0, right = matrix[0].size() - 1;
            int top = 0, bottom = matrix.size() - 1;
            
            int N = matrix.size() * matrix[0].size();
            vector<int> ans;

            while (ans.size() < N)
            {
               	//  Left to Right
                for (int i = left; i <= right && ans.size() < N; i++)
                {
                    ans.push_back(matrix[left][i]);
                }
                top++;

               	//   top to bottom 
                for (int i = top; i <= bottom && ans.size() < N; i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;

               	//  right to left
                for (int i = right; i >= left && ans.size() < N; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;

               	// bottom to up 
                for (int i = bottom; i >= top && ans.size() < N; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            return ans;
        }
};