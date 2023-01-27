class Solution
{
    public:
        vector<string> findAllConcatenatedWordsInADict(vector<string> &words, vector<string> res = {})
        {
            unordered_set<string> bag(words.begin(), words.end());
            for (const auto &word: words)
            {
                auto l = word.size();
                vector<bool> trace(l + 1, 0);
                trace[0] = 1;
                for (auto i = 1; i <= l; i++)
                    for (int j = i == l; !trace[i] and j < i; j++)	// explanation for this line given below
                        trace[i] = trace[j] && bag.count(word.substr(j, i - j));
                if (trace[l]) res.push_back(word);
            }
            return res;
        }
};