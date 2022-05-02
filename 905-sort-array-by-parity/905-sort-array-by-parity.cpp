class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 != 0) st.push(nums[i]);
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0) st.push(nums[i]);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};