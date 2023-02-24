class Solution
{
    public:
    int minimumDeviation(vector<int> &nums)
    {
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX;

        // Increasing all elements to as maximum as it can and track the minimum,
        // number and also the resultl
        for (int i = 0; i < n; ++i)
        {
            if ((nums[i] % 2) != 0)	// multiplication by 2 if nums[i] is odd
                nums[i] *= 2;	// maximising all odd numbers

            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }

        int min_deviation = mx - mn;

        priority_queue<int> pq;
        // Inserting into Priority queue (Max Heap) and try to decrease as much we can
        for (int i = 0; i < n; ++i)
        {
            pq.push(nums[i]);
        }

        while ((pq.top()) % 2 == 0)
        {
            int top = pq.top();
            pq.pop();	// popped the top element

            min_deviation = min(min_deviation, top - mn);
            top /= 2;
            mn = min(mn, top);	// updating min
            pq.push(top);	// pushing again the top as we have to minimize the max
        }

        min_deviation = min(min_deviation, pq.top() - mn);

        // we are returning mx - mn

        return min_deviation;
    }
};