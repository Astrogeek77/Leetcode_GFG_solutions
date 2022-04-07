class Solution {
public:
    void func(int i, vector<int> &nums, vector<int> &a, vector<vector<int>> &ans){
        ans.push_back(a);
        for(int j = i; j < nums.size(); j++){
            if(j != i && nums[j] == nums[j - 1]){
                continue;
            }
            a.push_back(nums[j]);
            func(j + 1, nums, a, ans);
            a.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        sort(nums.begin(), nums.end());
        func(0, nums, a, ans);
        return ans;
    }
};