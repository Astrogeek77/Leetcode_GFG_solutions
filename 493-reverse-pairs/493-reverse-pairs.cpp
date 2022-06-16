class Solution
{
    int Merge(vector<int> &nums, int low, int mid, int high)
    {
        int total = 0;
       	// intiatie j  from second half
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && nums[i] > (long)2 *nums[j])
            {
                j++;
            }
           	// total reverse pairs
            total += (j - (mid + 1));
        }

        vector<int> t;
        int left = low, right = mid + 1;

       	// merge step
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right]) t.push_back(nums[left++]);
            else t.push_back(nums[right++]);
        }

       	// left over values of either left or right part(if any)
        while (left <= mid) t.push_back(nums[left++]);
        while (right <= high) t.push_back(nums[right++]);

        // updating the original array
        for (int i = low; i <= high; i++) nums[i] = t[i - low];
        
        // return all pairs
        return total;
    }

    int MergeSort(vector<int> &nums, int low, int high)
    {
        // edge case
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        // left half
        int count = MergeSort(nums, low, mid);
        // right half
        count += MergeSort(nums, mid + 1, high);
        // merge step
        count += Merge(nums, low, mid, high);
        return count;
    }
    
public:
    int reversePairs(vector<int> &arr)
    {
        return MergeSort(arr, 0, arr.size() - 1);
    }
};

// Time Complexity : O( N log N ) + O (N) + O (N)   

// Reason : O(N) – Merge operation , O(N) – counting operation ( at each iteration of i , j doesn’t start from 0 . Both of them move linearly ) 

// Space Complexity : O(N) 

// Reason : O(N) – Temporary vector