class Solution
{
    public:
        int findMinArrowShots(vector<vector < int>> &points)
        {
            if (points.size() == 1)
                return 1;
            sort(points.begin(), points.end());
            int cnt = 0;
            for (int i = 0; i < points.size(); i++)
            {
                int j = i;
                while (j < points.size() && points[i][1] >= points[j][0])
                    points[i][1] = min(points[i][1], points[j++][1]);
                i = j - 1, cnt++;
            }
            return cnt;
        }
};