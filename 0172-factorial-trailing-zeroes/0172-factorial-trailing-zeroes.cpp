class Solution
{
    public:
    // Approach - 3 -> O(1)
    // int trailingZeroes(int n)
    // {
    //     return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125;
    // }

    // O(Log N)
    int trailingZeroes(int n)
    {
        int count = 0;
        for (int i = 5; i <= n; i *= 5)
        {
            count += n / i;
        }
        return count;
    }

   	// Approach - 2 -> O(Log N)
   	//     int trailingZeroes(int n)
   	//     {
   	//         int ans = 0;

   	//         while (n != 0)
   	//         {
   	//             n /= 5;
   	//             ans += n;
   	//         }
   	//         return ans;
   	//     }
};