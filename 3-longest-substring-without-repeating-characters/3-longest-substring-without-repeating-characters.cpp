class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            vector<int> chars(128, -1);
            int start = 0, end = 0;
            int n = s.size();
            int result = 0;

            while (end < n)
            {
                char c = s[end];
                int index = chars[c];

                while (index != -1 and index >= start and index < end)
                    start = index + 1;

                result = max(result, end - start + 1);
                chars[c] = end;
                end++;
            }
            return result;
        }
};