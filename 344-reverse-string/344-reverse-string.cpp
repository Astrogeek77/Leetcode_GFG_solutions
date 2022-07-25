class Solution
{
    public:
        void reverseString(vector<char> &s)
        {
            // swap the elements till the half of the vector size
            int n = s.size();
            for (int i = 0; i < n / 2; i++)
            {
                swap(s[i], s[n-i-1]);
            }
        }
};