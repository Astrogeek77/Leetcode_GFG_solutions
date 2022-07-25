class Solution
{
    public:
        vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
        {
           	// returning vector
            vector<int> res;

           	// search each element in num1, in num2
            for (auto x: nums1)
            {
                auto it = find(nums2.begin(), nums2.end(), x);

               	// if a match is found, push it to the result vector
                if (it != nums2.end())
                {
                    res.push_back(x);
                   	// and erase from nums2
                    nums2.erase(it);
                }
            }
            return res;
        }
};