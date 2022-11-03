// class Solution
// {
//     public:
//         int integerBreak(int n)
//         {
//             if (n <= 3) return n - 1;
//             else if (n % 3 == 0) return pow(3, n / 3);
//             else if (n % 3 == 1) return 4* pow(3, (n - 4) / 3);
//             else return 2* pow(3, n / 3);
//         }
// };

class Solution
{
    public:
        int f(int i, int sum)
        {
            if (i == 1) return 1;
            int notpick = f(i - 1, sum);
            int pick = 0;
            if (sum >= i) pick = i* f(i, sum - i);
            return max(pick, notpick);
        }

    int integerBreak(int n)
    {
        return f(n - 1, n);
    }
};

// https://leetcode.com/problems/integer-break/discuss/2469325/C%2B%2B-oror-Recursion-greaterMemoization-greaterTabulation-greaterSpaceOptimization