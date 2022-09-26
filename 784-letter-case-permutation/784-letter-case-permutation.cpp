class Solution
{
    vector<string> res;
    char changeCase(char c)
    {
        if (islower(c)) return toupper(c);
        else return tolower(c);
    }
    void backtrack(string temp, int idx)
    {
        res.push_back(temp);

        for (int i = idx; i < temp.size(); ++i)
        {
            if (isalpha(temp[i]))
            {
                temp[i] = changeCase(temp[i]);
                backtrack(temp, i + 1);
                temp[i] = changeCase(temp[i]);
            }
        }
    }
    public:
        vector<string> letterCasePermutation(string s)
        {
            backtrack(s, 0);
            return res;
        }
};