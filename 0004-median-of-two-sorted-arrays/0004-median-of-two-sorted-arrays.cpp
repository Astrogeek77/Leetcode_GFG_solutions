class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
           	// **Intuition  **
           	// I have to find out correct left half and correct right half
           	// i.e :	// 7,  || 12, 14, 15  --> parition it
           	//  1, 2, 3, 4, || 9, 11  --> parition it
           	// Now just findout max(left1,left2), min(right1,right2)

            int m = nums1.size();
            int n = nums2.size();

           	// int h1 = nums1[m-1], l1 = nums1[0];
           	// int h2 = nums[n-1], l2 = nums2[0];

            int N = m + n;

            if (n > m) return findMedianSortedArrays(nums2, nums1);

            int lo = 0, hi = n * 2;
            while (lo <= hi)
            {
                int mid2 = (lo + hi) / 2;	
                int mid1 = m + n - mid2;

                double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
                double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
                double R1 = (mid1 == m * 2) ? INT_MAX : nums1[(mid1) / 2];
                double R2 = (mid2 == n * 2) ? INT_MAX : nums2[(mid2) / 2];

                if (L1 > R2) lo = mid2 + 1;
                else if (L2 > R1) hi = mid2 - 1;
                else return (max(L1, L2) + min(R1, R2)) / 2;
            }
            return -1;
        }
};