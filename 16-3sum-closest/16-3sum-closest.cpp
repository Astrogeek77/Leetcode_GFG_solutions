class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int minimum = INT_MAX, result = 0;
       sort(nums.begin(), nums.end());
        
       if(nums.size() < 3)
        return {};
        
        
       for(int i = 0; i < nums.size() - 2; i++){
           if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
               int lo = i + 1, hi = nums.size() - 1;
               
               while(lo < hi){
                   int sum = nums[i] + nums[lo] + nums[hi];
                   
                   if(sum == target){
                      return sum;
                       
//                       while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
//                       while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                       
//                       lo++;
//                       hi--; 
                   } 
                  else if (sum < target) lo++;
                  else hi--; 
                   
                  if(minimum > abs(target - sum)){
                    minimum = abs(target - sum);
                    result = sum;
                }
               }
           }
       }
        return result;
    }
};

