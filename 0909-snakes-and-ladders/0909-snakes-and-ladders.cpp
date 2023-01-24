class Solution
{
    public:
        int snakesAndLadders(vector<vector < int>> &board)
        {
            int n = board.size();
            vector<vector<bool>> visited(n, vector<bool> (n, false));
            
            queue<int> q;
            q.push(1);
            
            visited[n - 1][0] = true;
            
            int count = 0;
            while (!q.empty())
            {
                int sz = q.size();
                while (sz--)
                {
                    int cur = q.front();
                    q.pop();
                   	// if reached the destination 
                    if (cur == n * n)
                        return count;
                   	// roll the dice, new value will be cur + dice
                    for (int dice = 1; dice <= 6; dice++)
                    {
                        if (cur + dice > n * n)
                            break;
                       	// get the new location
                        auto[x, y] = getcoordinates(cur + dice, n);
                        if (visited[x][y] == false)
                        {
                            visited[x][y] = true;
                            if (board[x][y] == -1)	// move to new location
                                q.push(cur + dice);
                            else	// if new location has snake or ladder, we need to move to that location
                                q.push(board[x][y]);
                        }
                    }
                }
                count++;
            }

            return -1;
        }
    pair<int, int> getcoordinates(int cur, int n)
    {
       	// from index cur, calculate the row and col
        int x = n - (cur - 1) / n - 1;
        int y = (cur - 1) % n;
        if (x % 2 == n % 2)
        {
        	// since alternating odd and even row the direction is reversed
            y = n - 1 - y;
        }
        return {
            x,
            y
        };
    }
};