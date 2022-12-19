class Solution
{
    public:
       	// Every grey code can be made from a smaller grey code one way then back flipped
        vector<int> grayCode(int n)
        {
            if (n == 1) return {0, 1};
            else
            {
                vector<int> gc = grayCode(n - 1);
                int N = gc.size();
                for (int i = N - 1; i >= 0; i--)
                {
                    gc.push_back((gc[i] << 1) + 1);
                    gc[i] <<= 1;
                }
                return gc;
            }
        }
};