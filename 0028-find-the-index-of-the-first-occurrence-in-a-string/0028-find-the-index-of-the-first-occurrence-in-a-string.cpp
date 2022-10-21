class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            if (needle.size() == 0) return 0;
            int end;

            for (int start = 0; start < haystack.size(); start++)
            {
                end = start;

                while (end < haystack.size() and haystack[end] == needle[end - start]) end++;
                if (end - start == needle.size()) return start;
            }
            return -1;
        }
};