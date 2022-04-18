class Solution
{
public:
    void func(int i, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            func(i + 1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> a;
        func(0, nums, ans);
        return ans;
    }
};