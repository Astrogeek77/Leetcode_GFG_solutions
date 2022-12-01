class Solution
{
    public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // deque to store indexes
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            // maintain k window
            while(!dq.empty() and i - dq.front() >= k) dq.pop_front();
        
            // check for maximum
            while(!dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};