// class Solution
// {
//     public:
//         bool containsDuplicate(vector<int> &nums)
//         {
//             return nums.size() > set<int> (nums.begin(), nums.end()).size();
//         }
// };

class Solution
{
    public:
        bool containsDuplicate(vector<int> &nums)
        {
            unordered_map<int, int> map;

            for (auto x: nums)
            {
                if (map.find(x) != map.end()) return true;
                map[x]++;
            }

            return false;
        }
};