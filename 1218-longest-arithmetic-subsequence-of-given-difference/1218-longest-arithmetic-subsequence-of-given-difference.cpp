// class Solution {
// public:
//     int helper(int index, int prev, vector<int>& arr, int diff){
//         int n = arr.size();
//         if(index >= n){
//             return 0;
//         }

//         int take = 0;
//         int notake = 0;
//         if(prev == -10000){
//             notake = helper(index + 1, prev, arr, diff);
//             take = 1 + helper(index + 1, arr[index], arr, diff);
//         }
//         else{
//             notake = helper(index + 1, prev, arr, diff);
//             if(arr[index] - prev == diff){
//                 take = 1 + helper(index + 1, arr[index], arr, diff);
//             }
//         }
//         return max(take, notake);
//     }
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int n = arr.size();
//         return helper(0, -10000, arr, difference);
//     }
// };
// class Solution {
//     public: 
//     int helper(int index, int prev, int[] arr, int diff) {
//         int n = arr.length;
//         if (index >= n) {
//             return 0;
//         }

//         int take = 0;
//         int notake = 0;
//         if (prev == -10000) {
//             notake = helper(index + 1, prev, arr, diff);
//             take = 1 + helper(index + 1, arr[index], arr, diff);
//         } else {
//             notake = helper(index + 1, prev, arr, diff);
//             if (arr[index] - prev == diff) {
//                 take = 1 + helper(index + 1, arr[index], arr, diff);
//             }
//         }
//         return Math.max(take, notake);
//     }

//     int longestSubsequence(int[] arr, int difference) {
//         int n = arr.length;
//         return helper(0, -10000, arr, difference);
//     }
// }

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        map<int,int>m;
        int mx=0;
        for(int i=0;i<arr.size();i++){
            m[arr[i]] = 1 + m[arr[i]-d];
            mx=max(mx,m[arr[i]]);
        }
        return mx;
    }
};