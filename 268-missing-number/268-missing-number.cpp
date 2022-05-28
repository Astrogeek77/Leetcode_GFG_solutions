class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum1 = 0;
        
        for(auto x: nums) sum1 += x;
        
        int sum2 = (n * (n+1)/2);
        
        return sum2 - sum1;
    }
};