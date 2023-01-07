class Solution
{
    public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        return gasCost(gas, cost);
    }

    int gasCost(vector<int> &gas, vector<int> &cost)
    {
        int remaining = 0, prev_remaining = 0, candidate = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            remaining += gas[i] - cost[i];
            if (remaining < 0)
            {
                candidate = i + 1;
                prev_remaining += remaining;
                remaining = 0;
            }
        }
        if (candidate == gas.size() or remaining + prev_remaining < 0)
            return -1;
        else 
            return candidate;
    }
};