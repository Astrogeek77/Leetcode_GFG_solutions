class Solution {
public:
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = 0;
        for (auto x : arr)
            sum += x;

        if (sum - d < 0 || (sum - d) % 2)
            return 0;
        int k = (sum - d) / 2;

        vector<int> prev(k + 1, 0), curr(k + 1, 0);

        if (arr[0] == 0)
            prev[0] = 2; // 2 cases -pick and not pick
        else
            prev[0] = 1; // 1 case - not pick

        if (arr[0] != 0 and arr[0] <= k)
            prev[arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            curr[0] = 1;
            for (int tar = 0; tar <= k; tar++)
            {
                int take = 0, ntake;
                ntake = prev[tar];

                if (tar >= arr[ind])
                    take = prev[tar - arr[ind]];
                curr[tar] = (take + ntake);
            }
            prev = curr;
        }
        return prev[k];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};