class Solution
{
    public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_set<string> bank(ideas.begin(), ideas.end());
        unordered_map<char, unordered_map<char, int>> map;

        for (string str: bank)
        {
            string s = str;
            char prev = s[0];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                s[0] = ch;
                // if (!bank.count(s))
                // {
                //     map[ch][prev]++;
                // }
                if(bank.find(s) == bank.end()) 
                    ++map[ch][prev];
            }
        }

        long long ans = 0;
        for (string str: bank)
        {
            string s = str;
            char prev = s[0];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                s[0] = ch;
                // if (!bank.count(s))
                // {
                //     ans += map[prev][ch]++;
                // }
                
                if(bank.find(s) == bank.end()) 
                   ans += map[prev][ch];
            }
        }
        return ans;
    }
};