class Solution
{
    public:
        int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
        {
            // store the start times, using map as we need the times in order.
            map<int, int> times;
            // {starttime -> {endtime, profit}}
            unordered_map<int, vector<pair<int, int>>> jobs;
            
            // push values into the maps
            for (auto i = 0; i < startTime.size(); ++i)
            {
                times[startTime[i]] = 0;
                jobs[startTime[i]].push_back({ endTime[i], profit[i] });
            }
            // result variable
            int max_profit = 0;
            
            // now we start with the biggest times
            for (auto it = times.rbegin(); it != times.rend(); ++it)
            {
                // look for jobs, with starttimes
                for (auto job: jobs[it->first])
                {
                    // calculate the lower bound for the end time of the job
                    auto it = times.lower_bound(job.first);
                    
                    // max profit = max (current Profit, Job profit plus maximum profit at the end of the job.)
                    max_profit = max(max_profit, (it == times.end() ? 0 : it->second) + job.second);
                }
                // update running profit
                it->second = max_profit;
            }
            // our answer
            return max_profit;
        }
};