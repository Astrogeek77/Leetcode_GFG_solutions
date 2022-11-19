class Solution
{
    public:
        /// Jarvis Algorithm
        vector<vector < int>> outerTrees(vector<vector<int>> &trees)
        {
            vector<vector < int>> upper;	// upper should be clockwise
            vector<vector < int>> lower;	// lower should be counter-clockwise
            set<vector < int>> uniq;

           	// Sort the coordinates of trees
            sort(trees.begin(), trees.end());

            for (auto &t: trees)
            {
               	// For upper (clockwise)
                while (upper.size() > 1 and
                       slope(upper[upper.size() - 2], upper[upper.size() - 1], t) > 0)
                    upper.pop_back();

               	// For lower (anti clockwise)
                while (lower.size() > 1 and
                       slope(lower[lower.size() - 2], lower[lower.size() - 1], t) < 0)
                    lower.pop_back();

                upper.push_back(t);
                lower.push_back(t);
            }

           	// Return the union of the coords in upper and lower
            for (auto &u: upper) uniq.insert(u);
            for (auto &l: lower) uniq.insert(l);
            
            return vector<vector<int>> (uniq.begin(), uniq.end());
        }

    int slope(vector<int> &c1, vector<int> &c2, vector< int > &c3)
    {
       	// m = (y3-y2)(x2-x1) - (x3-x2)(y2-y1) 
        return (c3[1] - c2[1]) * (c2[0] - c1[0]) - (c3[0] - c2[0]) * (c2[1] - c1[1]);
    }
};