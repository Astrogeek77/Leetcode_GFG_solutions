class Solution
{
    public:
        int maxSubarraySumCircular(vector<int> &nums)
        {
            /* we maintain five parameters
                -> sum -> total array sum at any point
                -> max_sum -> maximum sum subarray possible
                -> min_sum -> minimum sum subarray possible
                -> prev_max -> previous calc max
                -> prev_min  -> previous calc min 
            */
            
            int max_sum = nums[0], min_sum = nums[0], sum = nums[0], prev_min = nums[0], prev_max = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                sum += nums[i];

                prev_max = max(prev_max + nums[i], nums[i]);
                max_sum = max(max_sum, prev_max);

                prev_min = min(prev_min + nums[i], nums[i]);
                min_sum = min(min_sum, prev_min);
            }
            // check the last condition
            return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
        }
};