class Solution
{
    /*
        0 -> dead
        1 -> alive
        2 -> newly alive
        3 -> newly dead
    */
    bool check(int i, int j, int n, int m, vector<vector < int>> &board)
    {
        if (i >= 0 and j >= 0 and i < n and j < m)
        {
            return true;
        }
        return false;
    }

   	    int getNigh(vector<vector < int>> &board, int i, int j, int n, int m) 
   	    {
   	        int liveNgh = 0;
   	        int moveX[8] = {1, 1, 1, 0, 0, -1, -1, -1};
   	        int moveY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

   	        for(int k = 0; k < 8; k++)
   	        {
   	            int ni = i + moveX[k];
   	            int nj = j + moveY[k];

   	            if(check(ni, nj, n, m, board))
   	            {
   	                if(board[ni][nj] == 1 or board[ni][nj] == 3) liveNgh++;
   	            } 
   	        }
   	        return liveNgh;
   	    }

//     int getNigh(vector<vector < int>> &curr, int i, int j, int m, int n)
//     {
//         int liveNeighbours = 0;
//         if (i > 0)
//         {
//            	// check the upper neighbour
//             if (curr[i - 1][j] == 1 || curr[i - 1][j] == 3) liveNeighbours++;
//         }
//         if (i < m - 1)
//         {
//            	//check the lower neighbour
//             if (curr[i + 1][j] == 1 || curr[i + 1][j] == 3) liveNeighbours++;
//         }
//         if (j > 0)
//         {
//            	// check the left neighbour
//             if (curr[i][j - 1] == 1 || curr[i][j - 1] == 3) liveNeighbours++;
//         }
//         if (j < n - 1)
//         {
//            	// check the right neighbour
//             if (curr[i][j + 1] == 1 || curr[i][j + 1] == 3) liveNeighbours++;
//         }

//         if (i > 0 && j > 0)
//         {
//            	// check the top left neighbour
//             if (curr[i - 1][j - 1] == 1 || curr[i - 1][j - 1] == 3) liveNeighbours++;
//         }
//         if (i > 0 && j < n - 1)
//         {
//            	// check the top right neighbour
//             if (curr[i - 1][j + 1] == 1 || curr[i - 1][j + 1] == 3) liveNeighbours++;
//         }
//         if (i < m - 1 && j > 0)
//         {
//            	// check the bottom left neighbour
//             if (curr[i + 1][j - 1] == 1 || curr[i + 1][j - 1] == 3) liveNeighbours++;
//         }
//         if (i < m - 1 && j < n - 1)
//         {
//            	// check the bottom right neighbour
//             if (curr[i + 1][j + 1] == 1 || curr[i + 1][j + 1] == 3) liveNeighbours++;
//         }
//         return liveNeighbours;
//     }

    public:
        void gameOfLife(vector<vector < int>> &board)
        {
            int m = board.size();
            int n = board[0].size();
            
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int ln = getNigh(board, i, j, m, n);
                    if (board[i][j] == 0)
                    {
                       	//currently dead
                       	//can become alive if has exactly three live neighbours
                        if (ln == 3)
                        {
                            board[i][j] = 2;	//newly alive
                        }
                    }
                    else if (board[i][j] == 1)
                    {
                       	//<2 -> die
                       	//==2 || ==3 live
                       	//>3 ->die
                        if (ln < 2 || ln > 3)
                        {
                            board[i][j] = 3;	//newly dead
                        }
                    }
                }
            }
            
           	//final modifications 2->1, 3->0
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == 2) board[i][j] = 1;
                    else if (board[i][j] == 3) board[i][j] = 0;
                }
            }
        }
};