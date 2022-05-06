class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums;
        
        for(int i = 1; i < n; i++){
            fact = fact * i;  // calc factorial of n
            nums.push_back(i);  // push the numbers 0 - n-1
        }
        nums.push_back(n); // push the number n;
        
        string ans = ""; // result variable
        k--; // 0 based indexing
        
        while(true){
            int num = k / fact; // first number of the permutation
            ans += to_string(nums[num]); // gives the number for that index
            nums.erase(nums.begin() + num); // earse the num from the arr for next loop
            
            if(nums.size() == 0) break; 
            
            k = k % fact; // k value for next iteration
            fact = fact / nums.size(); // changing fact for next iteration;
        }
        return ans;
    }
};