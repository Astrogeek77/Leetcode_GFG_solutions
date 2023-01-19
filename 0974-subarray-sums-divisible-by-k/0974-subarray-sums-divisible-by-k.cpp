class Solution
{
    public:
    int subarraysDivByK(vector<int> &A, int K)
    {
        unordered_map<int, int> m;
        int sum = 0, res = 0;
        
        m[0] = 1;
        for (int x: A)
        {
            sum = ((sum + x) % K + K) % K;
            m[sum]++;
            
            if (m[sum] > 1)
                res += m[sum] - 1;
        }
        return res;
    }
};