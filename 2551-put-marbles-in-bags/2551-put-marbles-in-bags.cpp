class Solution {
public:
    long long putMarbles(vector<int>& wt, int k) 
    {
        vector<int> v;
        int n = wt.size();
        
        if(n == k) return 0;
        
        for(int i = 0; i < n-1; i++)
        {
            v.push_back(wt[i] + wt[i+1]);
        }
        
        sort(begin(v), end(v));
        
        long long size = v.size(), mini = 0, maxi = 0;
        for(int i = 0; i < k-1; i++)
        {
            mini += v[i];
            maxi += v[size - i - 1];
        }
        
        return maxi - mini;
    }
};