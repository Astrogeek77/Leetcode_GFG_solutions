class Solution
{
    public:
        int firstUniqChar(string s)
        {
            unordered_map<int, int> m;
            
            // store occuence frequency of each char of string
            for (int i = 0; i < s.length(); i++) m[s[i]]++;
            
            // check for the chars which frequency equal to 1
            for (int i = 0; i < s.length(); i++)
            {
                if (m[s[i]] == 1)
                {
                    return i;
                }
            }
            
            // if none found, return -1
            return -1;
        }
};
