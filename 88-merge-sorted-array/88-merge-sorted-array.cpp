class Solution
{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
        {
            int i = m - 1, j = n - 1, k = m + n - 1;
            while (i >= 0 and j >= 0)
            {
                if (nums1[i] < nums2[j])
                {
                    nums1[k--] = nums2[j--];
                   	// here nums2[j] is greater, so copy and decresase both
                }
                else
                {
                    nums1[k--] = nums1[i--];
                   	// here nums1[i] is greater/equal to, so copy and decresase both
                }
            }
           	// if left over numbers.
            while (j >= 0) nums1[k--] = nums2[j--];
        }
};