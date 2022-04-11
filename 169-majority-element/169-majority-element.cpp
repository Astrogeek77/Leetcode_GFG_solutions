class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore Voting Algo
        int count = 0;
        int candidate = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(count == 0) candidate = nums[i];
            
            if(candidate == nums[i]) count++;
            else count--;
        }
        return candidate;
    }
};