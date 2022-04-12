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

// class Solution {
// public:
//     int dp[101][101];
//     int solve(int m,int n){
//        if(m<0 || n<0) return 0;
//        if(m==0  || n==0) return 1;
//        if(dp[m][n]> 0) return dp[m][n];
//        else return dp[m][n]=solve(m-1,n) +solve(m,n-1); 
//     }
    
//     int uniquePaths(int m, int n) {
//         return solve(m-1,n-1);
//     }
// };


// class Solution {
// public:
//     // Combinoritics    
//     int uniquePaths(int m, int n) {
//  //         Total Directions = m + n - 2;
//         int total = m + n - 2;
//         double result = 1;
        
//         for(int i = 1; i <= (m - 1); i++){
//             result *= (total - (m - 1) + i)/ i;
//         }
//         return (int)result;
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};