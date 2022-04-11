class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Moore Voting Algo
        // Maximum 2 such nums are possible
        
        int count1 = 0;
        int count2 = 0;
        
        int first = INT_MAX;
        int second = INT_MAX;
        
        vector<int> ans;
        
        for(auto num : nums){
            if(num == first) count1++;
            else if(num == second) count2++;
            else if(count1 == 0) 
            {
                first = num;
                count1 = 1;
            } 
            else if (count2 == 0)
            {
                second = num;
                count2 = 1;
            } 
            else 
            {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for(auto num : nums)
        {
            if(num == first) count1++;
            else if(num == second) count2++;
        }
        
        if(count1 > (int)(nums.size()/3))
            ans.push_back(first);
        
        if(count2 > (int)(nums.size()/3))
            ans.push_back(second);
        
        
        return ans;
    }
};