class Solution
{
    public:
        bool isIsomorphic(string s, string t)
        {
            int arr1[256] = { 0
            }, arr2[256] = { 0 };
            for (int i = 0; i < min(s.size(), t.size()); ++i)
            {
                if (arr1[s[i]] != arr2[t[i]]) return false;
                arr1[s[i]] = arr2[t[i]] = i+1;
            }
            return true;
        }
};