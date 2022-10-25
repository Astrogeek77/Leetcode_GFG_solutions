class Solution
{
    public:
        bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
        {
            int wordIdx1 = 0, wordIdx2 = 0, chIdx1 = 0, chIdx2 = 0;
            while (true)
            {
                char ch1 = word1[wordIdx1][chIdx1];
                char ch2 = word2[wordIdx2][chIdx2];
                if (ch1 != ch2) return false;

                chIdx1++;
                chIdx2++;
                if (chIdx1 == word1[wordIdx1].size())
                {
                    wordIdx1++;
                    chIdx1 = 0;
                }
                if (chIdx2 == word2[wordIdx2].size())
                {
                    wordIdx2++;
                    chIdx2 = 0;
                }

                if (wordIdx1 == word1.size() && wordIdx2 == word2.size()) break;
                if (wordIdx1 == word1.size() || wordIdx2 == word2.size()) return false;
            }
            return true;
        }
};