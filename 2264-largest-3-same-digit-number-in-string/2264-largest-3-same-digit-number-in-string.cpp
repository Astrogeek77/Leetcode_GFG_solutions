class Solution
{
    public:
        string largestGoodInteger(string num)
        {
            vector<string> ans;  // vector of strings to store all the pairs
            int n = num.size();
            for (int i = 0; i <= n - 3; i++)
            {
                string s = num.substr(i, 3); // str under consideration
                if (s[0] == s[1] && s[1] == s[2]) ans.push_back(s); // all candidate strings pushed to the vector
            }
            sort(ans.rbegin(), ans.rend()); // sort the vector in reverse
            if (ans.empty()) return ""; // edge case
            return ans[0]; // first index contains the max string
        }
};