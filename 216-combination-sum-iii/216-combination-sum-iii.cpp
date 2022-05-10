class Solution {
    
    vector<vector<int>> result;
    
public:
    
    int sum(vector<int>& arr){
        int ans = 0;
        for(auto x: arr) ans += x;
        return ans;
    }
    
    void combinationSumHelper(int k, int n, vector<int>& combination, int num){
        
        if(k == 0){ 
            // if k becomes zero, check whether our sum of current selected combinations adds up to n or not
            if(sum(combination) == n )
                result.push_back(combination);
            return;
        }
        
        if(num > 9) return; // only 1-9 are to be used
        
        combination.push_back(num);
        combinationSumHelper(k - 1, n, combination, num + 1); // pick
        combination.pop_back();
        combinationSumHelper(k, n, combination, num + 1);    // not pick
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> combination;
        combinationSumHelper(k, n, combination, 1);
        return result;
        
    }
};