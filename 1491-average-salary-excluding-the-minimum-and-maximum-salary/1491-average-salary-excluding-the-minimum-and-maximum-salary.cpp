class Solution {
public:
    double average(vector<int>& salary) 
    {
        sort(salary.begin(),salary.end()); 
        int n = salary.size() - 2;
        int sum = accumulate(salary.begin()+1, salary.begin()+n+1,0);
        double res = sum*1.0 /n;
        return res;
    }
};