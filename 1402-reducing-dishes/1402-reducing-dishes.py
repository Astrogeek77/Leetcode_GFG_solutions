# class Solution
# {
#     public:
#     int maxSatisfaction(vector<int> &satisfaction)
#     {
#         vector<int> v = satisfaction;
#         sort(v.begin(), v.end(), greater<int>());
#         // reverse(v.begin(), v.end());
        
#         int sum = 0, ans = 0;
#         for (int x: v)
#         {
#             if (sum + x > 0)
#             {
#                 ans += sum + x;
#                 sum += x;
#             }
#         }
#         return ans;
#     }
# };


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        v = satisfaction
        v.sort(reverse=True)
        
        sum = 0
        ans = 0
        
        for x in v:
            if sum + x > 0:
                ans += sum + x
                sum += x
        return ans