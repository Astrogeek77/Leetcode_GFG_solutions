class Solution
{
    public:
        int minPartitions(string n)
        {
            int len = n.length();
            int max_digit_in_string = 0;

            for (auto element: n)
            {
               	// convert the string number into integer number by subtracting the ascii value.
                int digit = element - '0';
                max_digit_in_string = max(max_digit_in_string, digit);
            }

            return max_digit_in_string;
        }
};