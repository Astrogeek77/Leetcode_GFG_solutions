class Solution {
     // to check a config is valid or not
    bool check(int row, int col, vector<vector<char>> &board, char val)
    {
        // cout << val << endl;
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
    
    // solve sudoku
    bool helper(vector<vector<char>>& board) 
    {
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
                // find the empty cells
                if(board[row][col] == '.')
                {
                    // explore all posibile configs
                    for(char ch = '1'; ch <= '9'; ch++)
                    {
                        if(check(row, col, board, ch) == true)
                        {
                            board[row][col] = ch;
                            
                            if(helper(board) == true) return true;
                            else board[row][col] = '.';
                        }
                    }
                    // no config is possible
                    return false;
                }
            }
        }
        // the sudoku is solved
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        helper(board);
    }
};