class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) 
    {     
        int n = nums.size();   
        vector<int> v, ans;

        for(int i = 0; i < n; i++)
        {
            int idx = upper_bound(v.begin(), v.end(), nums[i]) - v.begin();           
            ans.push_back(idx + 1);
            
            if(idx == v.size()) 
            {
                v.push_back(nums[i]);
            }
            else
            {
                v[idx] = nums[i];
            }
        }  
        return ans;
    }
};