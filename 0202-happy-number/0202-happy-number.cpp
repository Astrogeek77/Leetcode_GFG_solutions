class Solution
{
    public:
        bool isHappy(int n)
        {
            int temp = n, sum = 0;
            unordered_set<int> s;
            s.insert(n);
            while (true)
            {
                sum = 0;
                while (temp)
                {
                    sum += (temp % 10) *(temp % 10);
                    temp /= 10;
                }
                if (sum == 1) return 1;
                if (s.count(sum) == 1) return 0;
                s.insert(sum);
                temp = sum;
            }
        }
};