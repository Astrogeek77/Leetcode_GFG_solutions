class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int, int> map;
        
        for(int task: tasks) map[task]++;
        
        int ans = 0;
        
        for(pair<int, int> x: map)
        {
            int freq = x.second;
            
            if(freq == 1) return -1;
            ans += freq % 3 == 0 ? freq / 3 : freq / 3 + 1;
        }
        
        return ans;
    }
};