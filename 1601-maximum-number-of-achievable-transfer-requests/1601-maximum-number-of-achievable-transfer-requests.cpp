class Solution {
public:
    void backtrack(vector<vector<int>>& requests, int index, vector<int>& count, int currCount, int& maxCount) {
        // Base case: If all requests have been processed
        if (index == requests.size()) {
            // Check if all buildings have a balanced count
            for (int i = 0; i < count.size(); i++) {
                if (count[i] != 0) return; // Some building is unbalanced, return
            }
            // Update the maximum count if the current count is greater
            maxCount = max(maxCount, currCount);
            return;
        }

        // Process the current request
        int from = requests[index][0];
        int to = requests[index][1];
        count[from]--; // Decrease count of "from" building
        count[to]++;   // Increase count of "to" building

        // Recursively process the next request with the current count incremented
        backtrack(requests, index + 1, count, currCount + 1, maxCount);

        // Undo the previous changes (backtracking)
        count[from]++; // Undo count change for "from" building
        count[to]--;   // Undo count change for "to" building

        // Recursively process the next request with the current count
        backtrack(requests, index + 1, count, currCount, maxCount);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> count(n); // Initialize count of buildings to 0
        int maxCount = 0;     // Maximum count of balanced requests
        backtrack(requests, 0, count, 0, maxCount); // Start backtracking from index 0
        return maxCount;     // Return the maximum count
    }
};
