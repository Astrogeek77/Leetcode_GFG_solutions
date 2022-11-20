class Solution {
public:
    int firstMissingPositive(vector<int>& A) 
    {
        int n = A.size();
        
        // for every number in range (0, n] swap all
        for (int i = 0; i < n; ++i)
        {
            while (A[i] > 0 and A[i] <= n and A[A[i] - 1] != A[i])
            {
                swap(A[i], A[A[i] - 1]);
            }
        }
        
        // now check for the first number that is not equal to i+1.
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != i + 1) return i + 1;
        }
        
        // if no num found return n+1
        return n + 1;
    }
};