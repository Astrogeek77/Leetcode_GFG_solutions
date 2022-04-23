class Solution {
public:
    int helper(vector<int> &nums){
        int n = nums.size();
        // 	vector<int> dp(n, 0);
        int prev = nums[0], prev2 = 0, curr;

        for(int i = 1; i < n; i++){

            int pick = nums[i];
            if(i > 1) pick += prev2;
            int npick = 0 + prev;

            curr = max(pick, npick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        
        if(n == 1) return nums[0];
        
        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n - 1) temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};