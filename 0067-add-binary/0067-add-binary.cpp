class Solution
{
    public:
        string addBinary(string a, string b)
        {
            // mark pointers at the end of strings
            int i = a.length() - 1;
            int j = b.length() - 1;
            
            string ans;
            int carry = 0;

            while (i >= 0 || j >= 0 || carry)
            {
                if (i >= 0)
                {
                    carry += a[i] - '0';
                    i--;
                }
                if (j >= 0)
                {
                    carry += b[j] - '0';
                    j--;
                }
                
                ans += (carry % 2 + '0');
                cout << "ans: " << ans << endl;
                
                carry = carry / 2;
                cout << "carry: " << carry << endl;
            }
            
            reverse(ans.begin(), ans.end());
            return ans;
        }
};