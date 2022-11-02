class Solution
{
    public:
        int chalkReplacer(vector<int> &chalk, int k)
        {

            long long sum = 0;
            for (auto x: chalk) sum += x;

            k %= sum;
            for (int i = 0; i < chalk.size(); i++)
            {
                if (k - chalk[i] < 0) return i;
                else k -= chalk[i];
            }
            return chalk.size() - 1;
        }
};