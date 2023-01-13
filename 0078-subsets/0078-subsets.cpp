class Solution
{
    public:
    void solve(int idx, vector<int> &nums, vector<vector< int >> &ans, vector< int > v)
    {
        // we explored all the possibilities
        if (idx >= nums.size())
        {
        /* 
            push the leaf terminating node in the recursion 
            tree to the answer vector. 
        */
            ans.push_back(v);
            return;
        }
        
        /* 
            for every idx we have two possibilites
            -> pick the nums[idx] element
            -> leave the element
        */

        // recursive call for next index without picking a elememt
        solve(idx + 1, nums, ans, v);

        // pick a element and push to the vector v.
        int el = nums[idx];
        v.push_back(el);
        // recursive call for next index, picking a elememt
        solve(idx + 1, nums, ans, v);
    }
    
    vector<vector < int>> subsets(vector<int> &nums)
    {
        // configs
        vector<vector < int>> ans;
        vector<int> v;
        int idx = 0;
        
        // initiate the call from idx = 0
        solve(0, nums, ans, v);
        // sort(ans.begin(), ans.end());
        return ans;
    }
};