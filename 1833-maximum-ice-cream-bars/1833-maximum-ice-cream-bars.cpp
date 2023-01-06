class Solution
{
    public:
        int maxIceCream(vector<int> &costs, int coins)
        {
            sort(costs.begin(), costs.end());
            int cnt = 0, prevSum = 0;

            for (int i = 0; i < costs.size(); i++)
            {
                if (costs[i] + prevSum <= coins)
                {
                    cnt++;
                    prevSum += costs[i];
                }
            }
            return cnt;
        }
};