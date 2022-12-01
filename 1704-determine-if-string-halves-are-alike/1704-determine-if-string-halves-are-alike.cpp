class Solution
{
    public:
        bool halvesAreAlike(string s)
        {
            int a = 0;
            int b = 0;
            int n = s.size();
            for (int i = 0; i < n / 2; i++)
            {
                if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u') b++;
            }
            for (int i = n / 2; i < n; i++)
            {
                if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u') a++;
            }
            if (a == b) return true;
            return false;
        }
};