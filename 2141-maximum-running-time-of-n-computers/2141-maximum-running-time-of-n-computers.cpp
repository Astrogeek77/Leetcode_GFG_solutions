class Solution {
public:
    // Function to calculate the maximum run time for the given number of batteries 'n'
    // and the vector 'bat' containing battery times
    long long maxRunTime(int n, vector<int>& bat) {
        long long total_time = 0; // Variable to store the total time of all batteries
        for(auto x : bat) total_time += x; // Calculate the total time by summing all battery times
        
        sort(bat.rbegin(), bat.rend()); // Sort the battery times in non-ascending order
        
        // Loop through the sorted battery times and try to optimize the run time
        for(int i = 0; i < bat.size(); i++, n--) {
            // If the current battery time is less than or equal to the average time (total_time/n),
            // then it won't be a bottleneck, so we can stop optimizing further
            if(bat[i] <= (total_time / n)) break;
            
            total_time -= bat[i]; // Reduce the total time by the current battery time
        }
        
        return total_time / n; // Return the optimized maximum run time
    }
};