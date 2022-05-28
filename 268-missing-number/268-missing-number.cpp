// class Solution
// {
//     public:
//         int missingNumber(vector<int> &nums)
//         {
//             int n = nums.size(), sum1 = 0;

//             for (auto x: nums) sum1 += x;

//             int sum2 = (n *(n + 1) / 2);

//             return sum2 - sum1;
//         }
// };

class Solution
{
    public:
        int missingNumber(vector<int> &nums)
        {
            int target = nums.size() *(nums.size() + 1) / 2;
            int sum = accumulate(nums.begin(), nums.end(), 0);
            return target - sum;
        }
};