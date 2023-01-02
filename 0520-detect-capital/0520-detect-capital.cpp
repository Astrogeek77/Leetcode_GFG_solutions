class Solution
{
    public:
    bool detectCapitalUse(string word)
    {
        int cnt = 0;
        for (char c: word) if ('Z' - c >= 0) cnt++;
        
        bool ans = (cnt == 0) or (cnt == word.size()) or (cnt == 1 and 'Z' - word[0] >= 0);
        return ans;
    }
};