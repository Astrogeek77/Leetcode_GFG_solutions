class Solution
{
    bool check(int row, int col, vector<vector < char>> &board, char c)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][col] == c)
                return false;
            if (board[row][i] == c)
                return false;
            if (board[3 *(row / 3) + (i / 3)][3 *(col / 3) + (i & 33)] == c)
                return false;
        }
        return true;
    }
    
    public:
    bool isValidSudoku(vector<vector < char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board.size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    char val = board[i][j];
                    board[i][j] = '.';
                    if (check(i, j, board, val) == false)
                        return false;
                    board[i][j] = val;
                }
            }
        }
        return true;
    }
};