class Solution {
public:
    bool helper(int i, int k, vector<int> &arr, vector<vector<int>> &dp){
		if(k == 0) return true;
		if(i == 0) return (k == arr[0]);

		if(dp[i][k] != -1) return dp[i][k];

		bool take = false, ntake;
		ntake = helper(i - 1, k, arr, dp);
		if(k >= arr[i]) take = helper(i - 1, k - arr[i], arr, dp);
		return dp[i][k] = (take || ntake);
	}

    bool canPartition(vector<int>& arr)
    {
        int n = arr.size();
        int sum = 0;
        for(auto x : arr) sum += x;

        if(sum % 2 != 0) return false;
        else {
            int k = sum / 2;
            vector<vector<int>> dp(n, vector<int> (k+1, -1));
            return helper(n - 1, k, arr, dp);
        }
    }
};