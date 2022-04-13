class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];
            if(map.find(temp) != map.end()) return {map[temp], i};
            else map[nums[i]] = i;
        }
        return {};
    }
};