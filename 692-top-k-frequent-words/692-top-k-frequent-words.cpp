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
            for (int i = 0; i < words.size(); i++) mp[words[i]]++;
            
            for (auto &i: mp) v.push_back(i);
            
            sort(v.begin(), v.end(), cmp);
            
            int x = 0;
            vector<string> ans(k);
            
            for (auto &i: v)
            {
                ans[x++] = i.first;
                if (k == x) break;
            }

            return ans;
        }
};