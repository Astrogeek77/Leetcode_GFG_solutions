class Solution
{
    public:
    int trailingZeroes(int n)
    {
        return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125;
    }
    
    // Approach - 2 O(N)
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