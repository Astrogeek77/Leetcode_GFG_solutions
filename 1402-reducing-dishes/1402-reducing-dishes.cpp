class Solution
{
    public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        vector<int> v = satisfaction;
        sort(v.begin(), v.end(), greater<int>());
        // reverse(v.begin(), v.end());
        
        int sum = 0, ans = 0;
        for (int x: v)
        {
            if (sum + x > 0)
            {
                ans += sum + x;
                sum += x;
            }
        }
        return ans;
    }
};