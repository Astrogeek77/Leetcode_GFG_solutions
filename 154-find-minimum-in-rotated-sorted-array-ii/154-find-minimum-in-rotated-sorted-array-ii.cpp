class Solution
{
    public:
        int findMin(vector<int> &num)
        {
            int lo = 0, hi = num.size() - 1;

            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (num[mid] < num[hi]) hi = mid;
                else if (num[mid] > num[hi]) lo = mid + 1;
                else hi--;
            }

            return num[lo];
        }
};