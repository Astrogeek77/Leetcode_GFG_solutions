class Solution
{
    public:
        int nextGreaterElement(int n)
        {
            string s = to_string(n);
            int len = s.size();
            for (int k = len - 2; k >= 0; k--)
            {
                if (s[k] < s[k + 1])
                {
                    int i = k + 1;
                    while (i < len - 1 && s[i + 1] > s[k]) i++;
                    swap(s[k], s[i]);
                    
                    reverse(s.begin() + k + 1, s.end());
                    return (len == 10 && s > "2147483647") ? -1 : stoi(s);
                }
            }
            return -1;
        }
};