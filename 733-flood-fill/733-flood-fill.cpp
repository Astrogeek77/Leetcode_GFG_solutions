class Solution
{
    public:
        void floodColor(vector<vector < int>> &image, int sr, int sc, int row, int col, int color, int target)
        {
            if (sr < 0 || sc < 0 || sr >= row || sc >= col) return;
            
            if (image[sr][sc] == target)
            {
                image[sr][sc] = color;
                floodColor(image, sr + 1, sc, row, col, color, target);
                floodColor(image, sr - 1, sc, row, col, color, target);
                floodColor(image, sr, sc + 1, row, col, color, target);
                floodColor(image, sr, sc - 1, row, col, color, target);
            }
        }
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
    {
        int row = image.size();
        int col = image[0].size();
        if (image[sr][sc] != color) floodColor(image, sr, sc, row, col, color, image[sr][sc]);
        return image;
    }
};