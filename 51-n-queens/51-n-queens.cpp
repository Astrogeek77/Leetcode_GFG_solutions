class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int rowdup = row;
        int coldup = col;
        
        while(col >= 0 && row >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
            row--;
        }
        
        row = rowdup;
        col = coldup;
        
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = rowdup;
        col = coldup;
        
        while(row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int i, vector<vector<string>> &ans, vector<string> &board, int n){
        if(i == n){
            ans.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isSafe(j, i, board, n)){
                board[j][i] = 'Q';
                solve(i + 1, ans, board, n);
                board[j][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        
        solve(0, ans, board, n);
        return ans;
    }
};