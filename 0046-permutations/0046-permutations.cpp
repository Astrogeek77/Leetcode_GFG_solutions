class Solution 
{
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
	void permuteRecursive(vector<int> &num, int idx, vector<vector<int> > &result)	{
		if (idx >= num.size()) 
        {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		
		for (int i = idx; i < num.size(); i++) 
        {
		    swap(num[idx], num[i]);
		    permuteRecursive(num, idx + 1, result);
		    // undo
		    swap(num[i], num[idx]);
		}
    }
public:
    vector<vector<int> > permute(vector<int> &num) 
    {
	    vector<vector<int>> result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
   
};