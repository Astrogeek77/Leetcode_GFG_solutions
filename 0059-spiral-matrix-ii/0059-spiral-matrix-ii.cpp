class Solution
{
    public:
        vector<vector < int>> generateMatrix(int n)
        {
            if (n == 0) return {};
            int left = 0, right = n - 1;
            int top = 0, bottom = n - 1;
            vector<vector < int>> ans(n, vector<int> (n, 0));
            int N = n * n;
            int count = 1;

            while (count != (n *n + 1))
            {
               	//  Left to Right
                for (int i = left; i <= right; i++)
                {
                    ans[top][i] = count;
                    count++;
                }
                top++;

               	//   top to bottom 
                for (int i = top; i <= bottom; i++)
                {
                    ans[i][right] = count;
                    count++;
                }
                right--;

               	//  right to left
                for (int i = right; i >= left; i--)
                {
                    ans[bottom][i] = count;
                    count++;
                }
                bottom--;

               	// bottom to up 
                for (int i = bottom; i >= top; i--)
                {
                    ans[i][left] = count;
                    count++;
                }
                left++;
            }
            return ans;
        }
};