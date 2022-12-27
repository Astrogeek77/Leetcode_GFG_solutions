class Solution
{
    public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = rocks.size(), count = 0;

        for (int i = 0; i < n; i++) rocks[i] = capacity[i] - rocks[i];

        sort(rocks.begin(), rocks.end());

        for (int i = 0; i < n and rocks[i] - additionalRocks <= 0; i++)
        {
            count++;
            additionalRocks -= rocks[i];
        }
        return count;
    }
};