class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
           	// sort array 
            sort(arr.begin(), arr.end(), [& x](int a, int b)
            {
                return (abs(a - x) == abs(b - x) ? a < b : abs(a - x) < abs(b - x));
	});

            vector<int> ans(min(k, (int) arr.size()));

           	// store first k values
            for (int i = 0; i < min(k, (int) arr.size()); i++)
            {
                ans[i] = arr[i];
            }

            sort(ans.begin(), ans.end());
            return ans;
        }
};