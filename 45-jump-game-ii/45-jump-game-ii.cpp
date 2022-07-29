//window[l...r]
class Solution
{
    public:
        int jump(vector<int> &nums)
        {
            if (nums[0] == 0 || nums.size() == 1) return 0;	//if only 1 element or first element is 0, then no jump needed/possible.
           	//initially jump=1 because we jumped from first element to window.
            int l = 1, r = nums[0], jumps = 1, maxReach;
           	//this while loop will run till r==index of last element(reached) or r>index of last element(can be easily reached).
            while (r < (nums.size() - 1))
            {
                maxReach = INT_MIN;
                for (int i = l; i <= r; i++)
                {
                    maxReach = max(maxReach, nums[i] + i);	//find max reachable position by an element inside window.
                }
                l = r + 1;	//next window starts right after prev window
                r = maxReach;	//new window ends at, max reached position from elements of prev window.
                jumps++;	//jump after selecting max reach in each window
            }
            return jumps;
        }
};
/*eg:- 2,3,0,1,4
jumps=1 (We jumped from first element to window)
initial window: 2,3(l),0(r),1,4
maxreach=3+1=4;
increase number of jumps.
change l and r for next window: 2,3,0,1(l),4(r).
since r reached last element i.e.,(r>=last element index) we stop.
return jumps.*/