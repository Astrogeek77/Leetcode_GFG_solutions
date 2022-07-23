class Solution
{
    public:
        int mySqrt(int x)
        {
           	// Binary Search Method

            if (x == 0 or x == 1) return x;

            long long X = (long long) x;
            long long l = 1;
            long long r = x / 2;
            long long res;

            while (l <= r)
            {
                long long mid = (l + r) / 2;

                if (mid *mid == X)
                {
                    res = mid;
                    break;
                }
                else if (mid * mid > X) r = mid - 1;
                else
                {
                    res = mid;
                    l = mid + 1;
                }
            }
            return res;
        }
};