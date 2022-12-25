class Solution
{
    public:
        vector<int> answerQueries(vector<int> A, vector<int> &queries)
        {
            // sort vector
            sort(A.begin(), A.end());
            
            vector<int> res;
            
            // prefix sum approach
            for (int i = 1; i < A.size(); ++i)  A[i] += A[i - 1];
                
            // upper bound to get the value greator than q, if any
            for (int &q: queries)
            {
                auto maxSumPt = upper_bound(A.begin(), A.end(), q);
                res.push_back(maxSumPt - A.begin());
            }
            return res;
        }
};