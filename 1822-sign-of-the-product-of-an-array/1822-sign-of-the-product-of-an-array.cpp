class Solution
{
    public:
    int arraySign(vector<int> &nums)
    {
        bool flag = false;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                cnt++;
            if (nums[i] == 0)
                flag = true;
        }
        if (flag)
            return 0;
        if (cnt % 2 == 0)
            return 1;
        else
            return -1;
    }
};