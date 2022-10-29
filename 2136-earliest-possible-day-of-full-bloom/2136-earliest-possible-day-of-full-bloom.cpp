class Solution
{
    public:
        int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
        {
            vector<pair<int, int>> v;	
            int len = plantTime.size();

            for (int i = 0; i < len; i++)
            {
                v.push_back({ growTime[i],
                    plantTime[i] });	
            }

            sort(v.begin(), v.end());	

            int time = 0;
            int max_days = 0;

            for (int i = len - 1; i >= 0; i--)
            {

                time += v[i].second;	

                max_days = max(max_days, time + v[i].first);
            }

            return max_days;
        }
};