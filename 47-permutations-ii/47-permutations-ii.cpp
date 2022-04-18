class Solution
{
public:
    unordered_map<int, int> map;
    vector<int> temp;
    
    void func(int i, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (i == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for (auto k : map)
        {
            int key = k.first;
            int value = k.second;
            
            if(value == 0) continue;   
            temp.push_back(key);
            map[key]--;
            
            func(i + 1, nums, ans);
            
            temp.pop_back();
            map[key]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        for(auto x: nums) map[x]++;
        
        func(0, nums, ans);
        return ans;
    }
};