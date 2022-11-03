class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            int len = 0;
            int n = words.size();
            vector<vector < int>> count(26, vector<int> (26, 0));

            for (string word: words)
            {
                int a = word[0] - 'a';
                int b = word[1] - 'a';

                // for words whose reverse is available
                if (count[b][a])
                {
                    len += 4;
                    count[b][a]--;
                }
                else count[a][b]++;
            }

            //for same words
            for (int i = 0; i < 26; i++)
            {
                if (count[i][i])
                {
                    len += 2;
                    break;
                }
            }
            
            return len;
        }
};