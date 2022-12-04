class Solution
{
    static bool cmp(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
    public:
        vector<string> topKFrequent(vector<string> &words, int k)
        {
            unordered_map<string, int> mp;
            vector<pair<string, int>> v;
            
            // frquency of words
            for (int i = 0; i < words.size(); i++) mp[words[i]]++;
            // push to vector to sort according to frequency
            for (auto &x: mp) v.push_back(x);

            // sort using custom comparator
            sort(v.begin(), v.end(), cmp);

            int idx = 0;
            vector<string> ans(k);

            // top k frequent strings/words is our answer
            for (auto &x: v)
            {
                ans[idx++] = x.first;
                if (k == idx) break;
            }

            return ans;
        }
};