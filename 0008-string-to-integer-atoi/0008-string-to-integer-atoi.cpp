class Solution
{
    public:
        int myAtoi(string s)
        {
            int i = 0;
            bool negFound = false;
            
            // check for whitespaces
            while (i < s.size())
            {
                if (s[i] == ' ') i++;
                else break;
            }
            // check for the primary sign
            if (s[i] == '-')
            {
                negFound = true;
                i++;
            }
            else if (s[i] == '+') i++;

            long long num = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (s[j] >= '0' and s[j] <= '9')
                {
                    // convert s[j] into integer
                    num = num *10 + (s[j] - '0');
                    
                    // check for overflows
                    if (num >= INT_MAX) break;
                }
                else break;
            }

            if (negFound) num *= -1;
            
            // secondary overflow / underflow checks
            if (num <= INT_MIN) return INT_MIN;
            else if (num >= INT_MAX) return INT_MAX;
            // answer
            return num;
        }
};