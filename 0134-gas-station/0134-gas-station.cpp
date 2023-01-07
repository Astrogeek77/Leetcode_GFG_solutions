class Solution
{
    public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        return gasCost(gas, cost);
    }

    int gasCost(vector<int> &gas, vector<int> &cost)
    {
        // track current remaining gas / fuel, 
        // previous remaining gas / fuel, 
        // and the candidate station
        
        int remainingFuel = 0, prev_remainingFuel = 0, candidateStation = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            remainingFuel += gas[i] - cost[i];
            if (remainingFuel < 0)
            {
                candidateStation = i + 1;
                prev_remainingFuel += remainingFuel;
                remainingFuel = 0;
            }
        }
        
        if (candidateStation == gas.size() or remainingFuel + prev_remainingFuel < 0)
            return -1;
        
        return candidateStation;
    }
};