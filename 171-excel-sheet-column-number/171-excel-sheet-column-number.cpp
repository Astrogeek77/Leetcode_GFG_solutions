class Solution
{
    public:
        int titleToNumber(string columnTitle)
        {
           	// https://leetcode.com/problems/excel-sheet-column-number/discuss/1790101/C%2B%2B-oror-4-Lines-oror-Easy-To-UnderStand-oror-0ms-oror-100
            int res = 0;
            for (char c: columnTitle)
            {
                int d = c - 'A' + 1;
                res = res *26 + d;
            }
            
            return res;
        }
};