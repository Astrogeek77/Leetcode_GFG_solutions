class Solution
{
    public:
        static string orderlyQueue(string s, int k)
        {
            if (k == 1)
            {
                string ans = s;
               	// Append |s| to itself and look for the smallest string
               	// of as the same lenght as |s|.
                s += s;
                for (int i = 1; i < size(ans); ++i)
                    ans = min(ans, s.substr(i, size(ans)));

                return ans;
            }

           	// With k > 1 we can reorder |s| how we want, so sorting it
           	// will yield the lexicographically smallest one.
            sort(begin(s), end(s));
            return s;
        }
};