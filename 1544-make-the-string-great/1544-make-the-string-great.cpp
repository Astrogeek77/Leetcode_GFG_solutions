class Solution
{
    public:
        string makeGood(string s)
        {
            // result string
            string ans;

            // traverse the string
            for (int i = 0; i < s.size(); i++)
            {
                ans.push_back(s[i]);
                
                /*
                we push the current char into string and check 
                if the back of the string is bad match or not.
                */
                while (ans.size() && (ans.back() == s[i + 1] + 32 || ans.back() == s[i + 1] - 32))
                {
                    // if bad match we pop the char and inc i
                    ans.pop_back();
                    i++;
                }
            }
            return ans;
        }
};