class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int count = 0;
        
        for(auto &x : nums1)
            for(auto &y : nums2)
                map[x + y]++;
        
        for(auto &x : nums3)
            for(auto &y : nums4)
                count += map[-(x + y)];
        
        return count;
    }
};