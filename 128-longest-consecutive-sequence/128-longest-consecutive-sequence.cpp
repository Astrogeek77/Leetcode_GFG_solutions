class Solution {
public:
    int longestConsecutive(vector < int > & nums) {
        if(nums.size() == 0)
            return 0;
        
        set<int> s(nums.begin(), nums.end());
        
        int result = 0, count = 0;
        
        for(auto it = s.begin(); it != s.end(); it++){
            if(next(it) != s.end() && *(next(it)) - *it == 1) {
                count++;
                result = max(count, result);
            } else count = 0;
        }
        return result + 1;
    }
};