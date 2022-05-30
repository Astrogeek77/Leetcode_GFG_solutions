class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            int n;
            if (dividend == INT_MIN && divisor == -1) return INT_MAX;
            else
            {
                n = dividend / divisor;
                return n;
            }
        }
};