class Solution
{
    int sumDigit(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += ((n % 10) *(n % 10));
            n /= 10;
        }
        return sum;
    }
    public:

        bool isHappy(int n)
        {
            int temp = n;

            while (1)
            {
                if (temp == 89) return false;
                if (temp == 1) return true;
                temp = sumDigit(temp);
            }
        }
};