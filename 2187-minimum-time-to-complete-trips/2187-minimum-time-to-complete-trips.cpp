#define ll long long
class Solution
{
    public:
    ll minimumTime(vector<int> &time, int totalTrips)
    {
        // Initialize the search range for minimum completion time
        ll lo = 1;
        ll hi = *min_element(begin(time), end(time)) *static_cast<long> (totalTrips);

        // Binary search for minimum completion time
        while (lo < hi)
        {
            // Calculate the midpoint of the search range
            ll mid = (lo + hi) / 2;
            // Count the number of tasks that can be completed within m time
            if (numTrips(time, mid) >= totalTrips)
                // If enough tasks can be completed within m time, search for smaller time
                hi = mid;
            else
                // If not enough tasks can be completed within m time, search for larger time
                lo = mid + 1;
        }

        // Return the minimum completion time
        return lo;
    }

   	// Helper function to count the number of tasks that can be completed within a given time
     long numTrips(const vector<int>& times, long m) {
    // Calculate the sum of the floor division of m by each task completion time
    return accumulate(begin(times), end(times), 0L,
                      [&](long subtotal, int t) { return subtotal + m / t; });
  }
};