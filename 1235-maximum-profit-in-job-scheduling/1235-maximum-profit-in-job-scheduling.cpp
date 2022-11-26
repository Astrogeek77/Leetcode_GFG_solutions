class Solution
{
    vector<int> dp;
    struct Job
    {
        int st, en, profit;

        Job(int st, int en, int profit)
        {
            this->st = st;
            this->en = en;
            this->profit = profit;
        }

        bool operator < (const Job &job)
        {
            if (st != job.st)
            {
                return st < job.st;
            }

            if (en != job.en)
            {
                return en < job.en;
            }
            return profit > job.profit;
        }

        bool operator==(const Job &job)
        {
            if (en == job.en && st == job.st && profit == job.profit)
            {
                return true;
            }
            return false;
        }
    };

    public:

        int findNextJob(vector<Job> &jobs, int time, int start)
        {
            int end = jobs.size() - 1;
            if (jobs[end].st < time || start > end)
                return jobs.size();
            while (start < end)
            {
                int mid = (start + end) / 2;

                if (jobs[mid].st >= time)
                    end = mid;
                else
                    start = mid + 1;
            }

            return start;
        }

    int getMaxProfit(vector<Job> &jobs, int index)
    {
        if (index >= jobs.size() || index < 0)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int nextJobIndex = findNextJob(jobs, jobs[index].en, index + 1);
        dp[index] = max(jobs[index].profit + getMaxProfit(jobs, nextJobIndex), getMaxProfit(jobs, index + 1));

        return dp[index];
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
    {
        vector<Job> jobs;
        for (int i = 0; i < startTime.size(); i++)
        {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        dp.resize(jobs.size(), -1);
        sort(jobs.begin(), jobs.end());
        return getMaxProfit(jobs, 0);
    }
};