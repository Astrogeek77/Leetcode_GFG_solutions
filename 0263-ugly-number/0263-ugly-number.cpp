class Solution
{
    public:
        static bool isUgly(int n)
        {
            if (n <= 0) return false;

            for (const int d: { 2, 3, 5 })
            {
                while (n % d == 0) n /= d;
            }
            return n == 1;
        }
};