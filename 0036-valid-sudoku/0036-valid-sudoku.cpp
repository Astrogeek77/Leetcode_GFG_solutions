class Solution
{
    bool check(int row, int col, vector<vector<char>> &board, char val)
    {
        cout << val << endl;
        for(int k = 0; k < 9; k++)
        {
            // check row and col
            if(board[row][k] == val) return false;
            if(board[k][col] == val) return false;
            // to check the corresponding 3 x 3 square.
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
                        // replace the char with a random value
                        board[i][j] = '$';
                        
                        // check the row, col, and the 3x3 sqaure for the same value
                        if(check(i, j, board, val) == false) return false;
                        // place back the val
                        board[i][j] = val;
                    }
                }
            }
            return true;
        }
};