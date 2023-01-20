class Solution
{
    void helper(int idx, int n, vector<int> &nums, vector<int> &comb)
    {
       	// Size of the subsequence must be atleast 2. 
        if (comb.size() > 1)
            set.insert(comb);

        for (int i = idx; i < n; i++)
        {
           	// Add nums[i] to comb only when it is greater than the last element in comb.
            if (comb.size() == 0 || nums[i] >= comb.back())
            {
                comb.push_back(nums[i]);
                helper(i + 1, n, nums, comb);
                comb.pop_back();
            }
        }
    }
    public:
    // to store unique combinations only for end result.
    set<vector <int>> set;
    vector<vector <int>> findSubsequences(vector<int> &nums)
    {
       vector<int> comb;
       helper(0, nums.size(), nums, comb);
       return vector<vector < int>> (set.begin(), set.end());
    }

    
};