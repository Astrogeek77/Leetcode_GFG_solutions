class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> minnum(n);
        
        minnum[0] = nums[0];
        for(int i = 1; i < n; i++) minnum[i] = min(minnum[i-1], nums[i]); // find the min value in arr till the ith index and store in minnum array.
        
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and st.top() <= minnum[i]) st.pop(); // condition fail -> pop off stack
            
            if(!st.empty() and st.top() < nums[i]) return true; // condition pass -> return true.
            
            st.push(nums[i]); // push the next num to the stack
        }
        return false;  // no such pair exists 
    }
};