class Solution
{
    public:
        int findMin(vector<int> &num)
        {
            int lo = 0, hi = num.size() - 1;

            while (lo < hi)
            {
                if (num[lo] < num[hi]) return num[lo];

                int mid = lo + (hi - lo) / 2;

                if (num[mid] >= num[lo]) lo = mid + 1;
                else hi = mid;
            }

            return num[lo];
        }
};