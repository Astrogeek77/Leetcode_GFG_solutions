class Solution
{
    public:
        int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
        {

            int area1 = (ax2 - ax1) * (ay2 - ay1); // area of 1st rectangle
            int area2 = (bx2 - bx1) * (by2 - by1); // area of 2nd rectangle

            int overlap = 0; // we need to check for overlap to avoid double count.

            // condition for overlap
            int x = min(ax2, bx2) - max(ax1, bx1);
            int y = min(ay2, by2) - max(ay1, by1);

            // calculate overlap
            if (x > 0 && y > 0) overlap = x * y;

            // subtract from total area
            int totalArea = area1 + area2 - overlap;

            return totalArea;
        }
};

// TIme - O(1)
// Space - O(1)