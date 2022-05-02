// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         stack<int> st;
//         int n = nums.size();
//         vector<int> ans;
        
//         for(int i = 0; i < n; i++){
//             if(nums[i] % 2 != 0) st.push(nums[i]);
//         }
        
//         for(int i = 0; i < n; i++){
//             if(nums[i] % 2 == 0) st.push(nums[i]);
//         }
        
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int next = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                swap(nums[i], nums[next++]);
            }
        }
        return nums;
    }
};