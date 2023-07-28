class Solution 
{
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> arr(n, 0);
        
        for(int i = n - 1; i >= 0; i--)
        {
            arr[i] = nums[i];
            for(int j = i+1; j < n; j++)
            {
                arr[j] = max(nums[i] - arr[j], nums[j] - arr[j-1]);
            }
        }
        
        return arr[n-1] >= 0;
    }
};