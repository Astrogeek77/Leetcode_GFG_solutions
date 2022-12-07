class Solution
{
    bool helper(string &s1, string &s2, string &s3, int n1, int n2, int n3, vector<vector<int>> &memo)
    {
       	// n1, n2, n3 act as indexes for strings s1, s2, s3

       	// base case
        if (n1 < 0 and n2 < 0 and n3 < 0) return true;
        
        // memoize
        if(n1 >= 0 and n2 >= 0 and memo[n1][n2] != -1) return memo[n1][n2];

       	// Case - 1 last chars of s1 and s2 are same as s3, we can choose either
        if (n1 >= 0 and s1[n1] == s3[n3] and n2 >= 0 and s2[n2] == s3[n3])
        {
            bool ans1 = helper(s1, s2, s3, n1 - 1, n2, n3 - 1, memo);
            bool ans2 = helper(s1, s2, s3, n1, n2 - 1, n3 - 1, memo);

            return memo[n1][n2] = (ans1 || ans2);
        }
        // case 2 last chars of s1 and s3 match only
        else if (n1 >= 0 and s1[n1] == s3[n3])
        {
            return helper(s1, s2, s3, n1 - 1, n2, n3 - 1, memo);
        }
        // case 3 last chars of s3 and s2 match only
        else if (n2 >= 0 and s2[n2] == s3[n3])
        {
            return helper(s1, s2, s3, n1, n2 - 1, n3 - 1, memo);
        }
        else return false;
    }
    public:
        bool isInterleave(string s1, string s2, string s3)
        {
           	// check edge cases
            int size1 = s1.size();
            int size2 = s2.size();
            int size3 = s3.size();
            
            // we need to memoize the solutions
            vector<vector<int>> memo(size1 + 1, vector<int> (size2 + 1, -1));

           	// s3 = s2 + s1
            if (size3 != (size2 + size1)) return false;

           	// return ans
            return helper(s1, s2, s3, size1 - 1, size2 - 1, size3 - 1, memo);
        }
};