class Solution
{
    public:
        string removeDuplicates(string s)
        {
            int k = 2;
            vector<pair<char, int>> count;	// declare a vector to store a pair of char and int (works like a stack here.)

            for (int i = 0; i < s.size(); i++)
            {
                if (count.empty() || s[i] != count.back().first) count.push_back({ s[i],
                    1 });	// if s[i] != s[i-1] we push the char with 1 into vector
                else if (++(count.back().second) == k) count.pop_back();	// if any double is found we pop_back()
            }

            s = "";	// we contruct the string again with remaining chars
            for (auto &x: count) s += string(x.second, x.first);

            return s;
        }
};