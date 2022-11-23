class Solution
{
    bool check(int row, int col, vector<vector<char>> &board, int val)
    {
        for(int k = 0; k < 9; k++)
        {
            if(board[row][k] == val) return false;
            if(board[k][col] == val) return false;
            if(board[(row / 3) * 3 + k/3][(col/3) * 3 + k % 3] == val) return false; 
        }
        return true;
    }
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            // int n = board.size();
            // int m = board[0].size();

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if(board[i][j] != '.')
                    {
                        char val = board[i][j];
                        board[i][j] = '$';
                        
                        if(check(i, j, board, val) == false) return false;
                        board[i][j] = val;
                    }
                }
            }
            return true;
        }
};