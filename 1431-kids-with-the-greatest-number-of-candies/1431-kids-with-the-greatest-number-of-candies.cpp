class Solution
{
    public:
    vector<bool> kidsWithCandies(vector<int> &cd, int ex)
    {
        int mx = *max_element(cd.begin(), cd.end());
        vector<bool> ans;
        
        for (int c: cd)
        {
            if (c + ex >= mx) 
                ans.push_back(true);
            else 
                ans.push_back(false);
        }
        return ans;
    }
};