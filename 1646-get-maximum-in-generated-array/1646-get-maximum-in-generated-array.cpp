// first of all we eliminate the edge cases i.e n == 0;
// then we declare a vector, you can use a array, it's the same use here;
// we fill in the values of 0,1 indexes as given in the question.
// we Put in the exact conditions given in the question.
// we return the max_element (an stl function) to get the answer;

class Solution
{
    public:
        int getMaximumGenerated(int n)
        {
            if (n == 0)
            {
                return 0;
            }
            vector<int> answer(n + 1);
            answer[0] = 0;
            answer[1] = 1;
            for (int i = 1; 2 * i < n; i++)
            {
                answer[2 *i] = answer[i];
                answer[2 *i + 1] = answer[i] + answer[i + 1];
            }
            return* max_element(answer.begin(), answer.end());
        }
};