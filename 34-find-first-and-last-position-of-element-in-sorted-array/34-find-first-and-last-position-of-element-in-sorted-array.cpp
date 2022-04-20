class Solution {
public:
    int getStart(vector<int> &nums, int target, int n){
        if(nums[0] == target) return 0;
        int lo = 0, hi = n;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target && nums[mid - 1] < target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }
    
    int getEnd(vector<int> &nums, int target, int n){
        if(nums[n] == target) return n;
        int lo = 0, hi = n;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target && nums[mid + 1] > target) return mid;
            else if (nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums.size() == 0 || nums[0] > target || nums[n - 1] < target)
            return {-1, -1};
        
        int start = getStart(nums, target, n - 1);
        int end = getEnd(nums, target, n - 1);
        return {start, end};
    }
};