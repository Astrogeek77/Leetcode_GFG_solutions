class Solution
{
    private:
    int dfs(vector<vector<int>> &childs, string &s, int &ans, int i)
    {
        int temp1 = 0, temp2 = 0;
        for (int j: childs[i])
        {
            // result from childs
            int cur = dfs(childs, s, ans, j);
            // reject the path, if two same chars are found.
            if (s[i] == s[j]) continue;
            
            // longest->temp1 and secondLongest->temp2 child chains.
            if (cur > temp2) temp2 = cur;
            if (temp2 > temp1) swap(temp1, temp2);
        }
        ans = max(ans, temp1 + temp2 + 1);
        return temp1 + 1;
    }
    
    public:
    int longestPath(vector<int> &parent, string s)
    {
        int n = s.size(), 
        ans = 0;
        
        // keep track of childs
        vector<vector<int>> childs(n, vector<int> ());
        for (int i = 1; i < n; ++i)
            childs[parent[i]].push_back(i);
        
        // dfs to traverse all the possible paths
        dfs(childs, s, ans, 0);
        return ans;
    }

    
};