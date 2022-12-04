// Time: O(n), Space: O(N)

// class Solution
// {
//     public:
//     int minimumAverageDifference(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector <long long> prefixSum(n);
        
//         prefixSum[0] = nums[0];
        
//         for (auto i = 1; i < n; i++)
//         {
//             // prefix sum
//             prefixSum[i] = nums[i] + prefixSum[i - 1];
//         }
        
//         long long ans = LLONG_MAX, index = 0;
//         for (auto i = 0; i < n; i++)
//         {
//             // comparing averages
//             long long a = (prefixSum[i] / (i + 1));
//             long long b = i < n - 1 ? (prefixSum[n - 1] - prefixSum[i]) / (n - i - 1) : 0;
            
//             if (ans > abs(a - b)) ans = abs(a - b), index = i;
//         }
//         return index;
//     }
// };

// Time: O(n), Space: O(1)

class Solution
{
    public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0, curSum = 0;
        for (auto i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        long long ans = LLONG_MAX, index = 0;
        for (auto i = 0; i < n; i++)
        {
            curSum += nums[i];
            long long a = curSum / (i + 1);
            long long b = i < n - 1 ? (sum - curSum) / (n - i - 1) : 0;
            if (ans > abs(a - b))
            {
                ans = abs(a - b), index = i;
            }
        }
        return index;
    }
};