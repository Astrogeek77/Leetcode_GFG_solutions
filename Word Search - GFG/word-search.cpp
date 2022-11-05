//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        bool dfs(vector<vector < char>> &board, int i, int j, int idx, string &word)
        {
           	// base case
            if (idx == word.size()) return true;
            if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or board[i][j] != word[idx]) return false;
           	// char at the current indices
            char temp = board[i][j];
           	// temp hiding the char to avoid double count
            board[i][j] = ' ';	// replace with empty char

           	// search for all directions
            bool up = dfs(board, i - 1, j, idx + 1, word);
            bool left = dfs(board, i, j - 1, idx + 1, word);
            bool right = dfs(board, i, j + 1, idx + 1, word);
            bool bottom = dfs(board, i + 1, j, idx + 1, word);

           	// take OR of all results
            bool found = left or up or right or bottom;

           	// replace the hidden char
            board[i][j] = temp;
            return found;	// return result
        }

    bool isWordExist(vector<vector < char>> &board, string word)
    {
        int rows = board.size(), cols = board[0].size();	// get the total rows and columns
        for (int row = 0; row < rows; row++)
        {
        	// traverse for rows
            for (int col = 0; col < cols; col++)
            {
            	// traverse for columns
               	// after matching the first char we traverse for other matching chars using DFS (recursive)
                if (board[row][col] == word[0] and dfs(board, row, col, 0, word)) return true;
            }
        }
       	// no match is found
        return false;
    }
};   

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends