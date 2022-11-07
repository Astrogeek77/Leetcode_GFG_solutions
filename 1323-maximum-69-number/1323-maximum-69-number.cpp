class Solution
{
    public:
        int maximum69Number(int num)
        {
            int n = num;
            string ans = "";
            
            // convert to number
            while (num)
            {
                ans = to_string(num % 10) + ans;
                num = num / 10;
            }

            // convert 6 to 9
            for (int i = 0; i < ans.length(); i++)
            {
                if (ans[i] == '6')
                {
                    ans[i] = '9';
                    break;
                }
            }
            int res = 0;

            // convert back
            for (auto ch: ans)
            {
                res = res *10 + (ch - '0');
            }
            return res;
        }
};