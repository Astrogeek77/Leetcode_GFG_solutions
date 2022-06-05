class Solution
{
    public:
        bitset<100> col, rd, ld;

    int counter = 0;
    void nqueens(int row, int n)
    {
        if (row == n)
        {
            counter++;
            return;
        }

        for (int c = 0; c < n; c++)
        {
            if (!col[c] and!ld[row - c + n - 1] and!rd[row + c])
            {
                col[c] = ld[row - c + n - 1] = rd[row + c] = 1;
                nqueens(row + 1, n);
                col[c] = ld[row - c + n - 1] = rd[row + c] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {
        nqueens(0, n);
        return counter;
    }
};