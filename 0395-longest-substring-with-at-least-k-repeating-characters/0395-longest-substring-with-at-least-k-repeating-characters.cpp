class Solution {
    int helper(int lo, int hi, string s, int k)
    {
        if(hi < lo) return 0;
        
        // frequency of each char
        unordered_map<char, int> map;
        for(int i = lo; i <= hi; i++) map[s[i]]++;
        
        // calaculate breakpoint
        int breakpoint = -1;
        for(int i = lo; i <= hi; i++)
        {
            if(map[s[i]] < k and map[s[i]] > 0) { breakpoint = i; break; }
        }
        
        // if no breakpoint 
        if(breakpoint == -1) return hi - lo + 1;
        
        // check 0 - breakpoint substring and breakpoint to n substring
        int left = helper(lo, breakpoint - 1, s, k);
        int right = helper(breakpoint + 1,  hi, s, k);
        
        return left < right ? right : left;
    }
    
public:
    int longestSubstring(string s, int k) {
        return helper(0, s.size() - 1, s, k);
    }
};