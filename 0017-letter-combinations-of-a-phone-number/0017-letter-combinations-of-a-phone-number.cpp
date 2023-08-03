class Solution
{
    public:
        void helper(string &digits, string &seq, vector<string> &ans, unordered_map<char, string> &map, int idx)
        {
            // we have traversed the digit till end.
            if (idx == digits.size())
            {
                // a null check
                if (digits == "") return;
                // store the current generated sequence
                ans.push_back(seq);
                return;
            }

            char curr = digits[idx];	// for indexing
            string letters = map[curr];	// available letters

            for (int j = 0; j < letters.size(); j++)
            {
                // try all sequence combinations
                seq.push_back(letters[j]);
                // recursive call for the new sequence and inc the index
                helper(digits, seq, ans, map, idx + 1);
                // back track for next posible combination
                seq.pop_back();
            }
        }

    vector<string> letterCombinations(string digits)
    {

        unordered_map<char, string> map = {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" }
        };

        vector<string> ans;
        string seq = "";

        helper(digits, seq, ans, map, 0);
        return ans;
    }
};