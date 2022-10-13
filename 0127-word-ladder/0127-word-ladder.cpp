class Solution
{
    public:
        int ladderLength(string startWord, string targetWord, vector<string> &wordList)
        {
            queue<pair<string, int>> q;
            q.push({ startWord, 1 });
            unordered_set<string> set(wordList.begin(), wordList.end());
            set.erase(startWord);

            while (!q.empty())
            {
                string word = q.front().first;
                int steps = q.front().second;
                q.pop();
                
                if(word == targetWord) return steps;

                for (int i = 0; i < word.size(); i++)
                {
                    char org = word[i];

                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if (set.find(word) != set.end())
                        {
                            set.erase(word);
                            q.push({ word, steps + 1 });
                        }
                    }
                    word[i] = org;
                }
            }
            return 0;
        }
};