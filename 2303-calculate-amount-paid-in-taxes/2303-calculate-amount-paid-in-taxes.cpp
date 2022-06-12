class Solution
{
    public:
        double calculateTax(vector<vector < int>> &brackets, int income)
        {
            // answer
            double total = 0;
            // prev upper bound
            int prev = 0;
            for (int i = 0; i < brackets.size(); i++)
            {
                // check income for every value
                if (income > brackets[i][0])
                {
                    total += ((double) brackets[i][1] / 100) *(brackets[i][0] - prev);
                    prev = brackets[i][0]; // update prev
                }
                else
                {
                    total += ((double) brackets[i][1] / 100) *(income - prev);
                    break;
                }
            }
            return total;
        }
};