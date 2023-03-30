class Solution
{
    public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2)
    {
       	// base case
        if (s1 == s2)
            return true;
       	// create an unique key
        string key = s1 + "*" + s2;
       	// if already calculated
        if (mp.count(key))
            return mp[key];

        for (int i = 0; i < s1.size() - 1; i++)
        {
            if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)))
            {
                return mp[key] = true;
            }

            if (isScramble(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1)) && isScramble(s1.substr(i + 1), s2.substr(0, s2.size() - i - 1)))
            {
                return mp[key] = true;
            }
        }
       	// store the res and return it
        return mp[key] = false;
    }
};