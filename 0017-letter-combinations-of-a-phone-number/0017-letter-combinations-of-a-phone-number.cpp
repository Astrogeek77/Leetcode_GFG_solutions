class Solution
{
    public:
        void helper(string &digits, string &seq, vector<string> &ans, unordered_map<char, string> &map, int i)
        {
            if (i == digits.size())
            {
                if (digits == "") return;
                ans.push_back(seq);
                return;
            }

            char curr = digits[i];	// for indexing
            string letters = map[curr];	// available letters

            for (int j = 0; j < letters.size(); j++)
            {
                seq.push_back(letters[j]);
                helper(digits, seq, ans, map, i + 1);
                seq.pop_back();
            }
        }

    vector<string> letterCombinations(string digits)
    {

        unordered_map<char, string> map = {
		{
                '2',
                "abc" },
            {
                '3',
                "def" },
            {
                '4',
                "ghi" },
            {
                '5',
                "jkl" },
            {
                '6',
                "mno" },
            {
                '7',
                "pqrs" },
            {
                '8',
                "tuv" },
            {
                '9',
                "wxyz" }
        };

        vector<string> ans;
        string seq = "";

        helper(digits, seq, ans, map, 0);
        return ans;
    }
};