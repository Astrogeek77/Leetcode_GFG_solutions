class Solution
{
    public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        return helper(s, m, p, n);
    }

    bool helper(string &s, int i, string &p, int j)
    {
        if (i == 0 && j == 0) return true;
        if (i != 0 && j == 0) return false;
        
        if (i == 0 && j != 0)
        {
           	//in this case only p == "c*c*c*" this pattern can match null string
            if (p[j - 1] == '*')
            {
                return helper(s, i, p, j - 2);
            }
            else return false;
        }
       	//now both i and j are not null
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
        {
            return helper(s, i - 1, p, j - 1);
        }
        else if (p[j - 1] == '*')
        {
            if (helper(s, i, p, j - 2)) return true;
           	
            if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
            {
                return helper(s, i - 1, p, j);
            }
            else return false;
        }
        return false;
    }
};