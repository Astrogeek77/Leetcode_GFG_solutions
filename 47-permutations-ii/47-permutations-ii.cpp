// class Solution
// {
// public:
//     unordered_map<int, int> map;
//     vector<int> temp;
    
//     void func(int i, vector<int> &nums, vector<vector<int>> &ans)
//     {
//         if (i == nums.size())
//         {
//             ans.push_back(temp);
//             return;
//         }
//         for (auto k : map)
//         {
//             int key = k.first;
//             int value = k.second;
            
//             if(value == 0) continue;   
//             temp.push_back(key);
//             map[key]--;
            
//             func(i + 1, nums, ans);
            
//             temp.pop_back();
//             map[key]++;
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int> &nums)
//     {
//         vector<vector<int>> ans;
//         for(auto x: nums) map[x]++;
        
//         func(0, nums, ans);
//         return ans;
//     }
// };

class Solution
{
public:
    vector<vector<int>> ans;
    set<vector<int>> set;
    
    void helper(vector<int> &nums, int i, int j)
    {
        if(i == nums.size() and set.find(nums) == set.end()){
            ans.push_back(nums);
            set.insert(nums);
            return;
        }
        
        for(int k = i; k <= j; k++){
            swap(nums[k], nums[i]);
            helper(nums, i+1, j);
            swap(nums[k], nums[i]);
        }
        
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        helper(nums, 0, nums.size() - 1);
        return ans;
    }
};