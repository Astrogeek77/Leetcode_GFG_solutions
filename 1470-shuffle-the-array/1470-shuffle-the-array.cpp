class Solution 
{
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> ans;
        // ans.push_back(nums[0]);
        
        int left = 0;
        int right = n;
        
        while(left < n)
        {
            ans.push_back(nums[left++]);
            ans.push_back(nums[right++]);
        }
        return ans;
    }
};