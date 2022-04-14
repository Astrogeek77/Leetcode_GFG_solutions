class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < n; i++) 
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n; j++) 
            {
                if(j != (i+1) && nums[j] == nums[j-1]) continue;
                
                int rem = target - (nums[i] + nums[j]);
                int lo = j + 1, hi = n - 1;
                
                while(lo < hi)
                {
                    int sum = nums[lo] + nums[hi];
                    if(sum < rem) lo++;
                    else if(sum > rem) hi--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        if(nums[lo]==nums[hi]) break;
                        int x = nums[lo];
                        int y = nums[hi];
                        while(x == nums[lo]) lo++;
                        while(y == nums[hi]) hi--;
                    }
                }
            }
        }
        return ans;
    }
};