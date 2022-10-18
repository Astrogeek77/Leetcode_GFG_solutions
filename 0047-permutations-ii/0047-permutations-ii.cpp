class Solution
{
public:
    vector<vector<int>> ans;
    set<vector<int>> set;
    
    void helper(vector<int> &nums, int i, int j)
    {
        if(i == nums.size() and set.find(nums) == set.end()){
            ans.push_back(nums);
            set.insert(nums);
            return;
        }
        
        for(int k = i; k <= j; k++){
            swap(nums[k], nums[i]);
            helper(nums, i+1, j);
            swap(nums[k], nums[i]);
        }
        
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        helper(nums, 0, nums.size() - 1);
        return ans;
    }
};