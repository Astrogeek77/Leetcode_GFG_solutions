class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            if (s.size() < p.size())  return {}; // edge case

            int l = 0, r = -1;
            vector<int> freq_s(26, 0), freq_p(26, 0), res;
            for (int i = 0; i < p.size(); i++)
            {
                freq_p[p[i] - 'a']++;
                freq_s[s[++r] - 'a']++;
            }

            if (freq_s == freq_p) res.push_back(l);

            while (r < s.size() - 1)
            {
                freq_s[s[++r] - 'a']++;
                freq_s[s[l++] - 'a']--;
                if (freq_s == freq_p)  res.push_back(l);
            }
            return res;
        }
};