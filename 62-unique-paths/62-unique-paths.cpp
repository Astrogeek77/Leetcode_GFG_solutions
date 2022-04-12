// class Solution {
// public:
//     int countPaths(int i, int j, int m, int n){
//         if(i == (n - 1) && j == (m - 1)) return 1;
//         if(i >= n || j >= m) return 0;
//         return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
//     }
//     int uniquePaths(int m, int n) {
//         return countPaths(0, 0, m, n);
//     }
// };

class Solution {
public:
    // int mod=2e9;
    int dp[101][101];
    int solve(int m,int n){
       if(m<0 || n<0) return 0;
        else if(m==0  || n==0) return 1;
         else if(dp[m][n]>0) return dp[m][n];
        else{
            return dp[m][n]=solve(m-1,n) +solve(m,n-1); 
        }
    }
    int uniquePaths(int m, int n) {
        return solve(m-1,n-1);
    }
};