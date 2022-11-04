class DSU
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    unordered_map<int, int> size;

    public:
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findPar(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = findPar(parent[i]);
    }

    bool unionByRank(int a, int b)
    {
        int x = findPar(a), y = findPar(b);
        if (x == y) return false;

        if (rank[x] > rank[y]) parent[y] = x;
        else if (rank[x] < rank[y]) parent[x] = y;
        else
        {
            parent[x] = y;
            rank[x]++;
        }
        return true;
    }

    bool unionBySize(int a, int b)
    {
        int u = findPar(a), v = findPar(b);
        if (u == v) return false;

        if (size[u] < size[v])
        {
            parent[u] = v;
            size[v] += size[u];
        }
        else
        {
            parent[v] = u;
            size[u] += size[v];
        }
        return true;
    }
};

class Solution
{
    public:
    vector<vector < string>> accountsMerge(vector<vector < string>> &accounts)
    {
        int n = accounts.size();
        map<string, int> mp;
        
        DSU dsu(n);
        vector<vector < string>> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                // if account not seen before
                if (mp.find(accounts[i][j]) == mp.end()) mp[accounts[i][j]] = i;
                // else make a union
                else dsu.unionBySize(i, mp[accounts[i][j]]);
            }
        }

        vector<string> temp[n];

        for (auto it: mp)
        {
            temp[dsu.findPar(it.second)].push_back(it.first);
        }

        for (int i = 0; i < n; i++)
        {
            if (temp[i].size())
            {
                vector<string> emails = temp[i];
                sort(emails.begin(), emails.end());
                emails.insert(emails.begin(), accounts[i][0]);
                ans.push_back(emails);
            }
        }

        return ans;
    }
};