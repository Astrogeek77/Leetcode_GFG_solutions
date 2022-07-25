class Solution
{
    public:
        void moveZeroes(vector<int> &nums)
        {
           	//if we find any non zero elmt in the array, swap it with front index elmt and update both front, curr indexes. Else just update curr index.
            for (int i = 0, j = 0; j < nums.size(); j++)
            {
                if (nums[j] != 0)
                {
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
        }
};