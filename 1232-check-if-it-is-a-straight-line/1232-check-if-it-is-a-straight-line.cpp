class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) 
    {
        // in a straight line slope remains same for all points.
        double m; // initial slope
        if((c[1][0] - c[0][0]) == 0) 
        {
            // horizontal lines
            m = INT_MAX;
        }
        else 
        {
            // calculate slope
            m = 1.0 * (c[1][1] - c[0][1]) / (c[1][0] - c[0][0]);
        }

        for(int i=1; i<c.size() - 1; i++)
        {
            double k; // variable for next slopes.
            if((c[i+1][0] - c[i][0]) == 0) k = INT_MAX;
            else
            {
                k = 1.0 * (c[i+1][1] - c[i][1]) / (c[i+1][0] - c[i][0]);
            } 
                 
            // return false if slope not equal for all points.
            if(k != m) return false;
        }
        return true;
    }
};