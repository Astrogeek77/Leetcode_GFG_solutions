class Solution {
public:
   vector<vector<int>> threeSum(vector<int>& nums) {
	
	sort(nums.begin(),nums.end());
    
	//Base Case
    if(nums.size() < 3)
        return {};
    
    vector<vector<int>> ans;
    
    for(int i=0 ; i<nums.size()-2;i++)
    {
        if(i == 0 || (i>0 && nums[i]!=nums[i-1]))   
        {
            int lo =i+1 , hi=nums.size()-1 ;
            
            while(lo<hi)
            {
                int sum = nums[i]+nums[lo]+nums[hi];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[lo],nums[hi]});

					//to handle duplicates
                    while(lo<hi && nums[lo]==nums[lo+1]) 
                        lo++;
					
					//to handle duplicates
                    while(lo<hi && nums[hi]==nums[hi-1]) 
                        hi--;
                    
                    lo++;
                    hi--;

                }
				
				// If sum of three elements is less than zero then increment in "lo"
                else if(sum<0)  
                    lo++;
				
				// if sum is greater than zero than decrement in "hi"
                else  
                    hi--;       
            }
        }
    }
    return ans;        
}
};