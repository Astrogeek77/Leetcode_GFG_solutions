class Solution {
public:
    void printSubsequnce(int i, vector<int> &a, vector<int> arr, int n, vector<vector<int>> &ans)
    {
    if (i == n)
    {
        ans.push_back(a);
        return;
    }
    a.push_back(arr[i]);
    printSubsequnce(i + 1, a, arr, n, ans);
    a.pop_back();
    printSubsequnce(i + 1, a, arr, n, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        printSubsequnce(0, a, nums, nums.size(), ans);
        return ans;
    }
};