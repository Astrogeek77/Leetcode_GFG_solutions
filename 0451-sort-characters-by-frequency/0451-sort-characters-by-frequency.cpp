class Solution
{
    public:
        string frequencySort(string s)
        {
            // map the char frequency
            unordered_map<char, int> mp;
            for (auto ch: s)
            {
                mp[ch]++;
            }
            
            // queue to push pair of {freq, char}
            priority_queue<pair<int, char>> pq;
            for (auto it: mp)
            {
                pq.push({ it.second,
                    it.first });
            }
            
            // add to string while poping from top of pq
            string res;
            while (!pq.empty())
            {
                int val = pq.top().first;
                while (val--)
                {
                    res += pq.top().second;
                }
                pq.pop();
            }
            return res;
        }
};