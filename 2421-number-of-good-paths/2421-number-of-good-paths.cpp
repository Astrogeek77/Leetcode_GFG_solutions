// to be tried again !!

class DSU
{
    private:
    vector<int> id, rank;
    int cnt;
    
    public:
    DSU(int cnt): cnt(cnt)
    {
        id = vector<int> (cnt);
        rank = vector<int> (cnt, 0);
        for (int i = 0; i < cnt; ++i) id[i] = i;
    }
    
    int findPar(int p)
    {
        if (id[p] == p) return p;
        return id[p] = findPar(id[p]);
    }
    
    bool connected(int p, int q)
    {
        return findPar(p) == findPar(q);
    }
    
    void connect(int p, int q)
    {
        int i = findPar(p), j = findPar(q);
        // already connected / have common parent
        if (i == j) 
            return;
        
        if (rank[i] < rank[j])
            id[i] = j;
        else
        {
            id[j] = i;
            if (rank[i] == rank[j]) rank[j]++;
        }
        // decrease component count.
        --cnt;
    }
};

class Solution
{
    public:
    int numberOfGoodPaths(vector<int> &vals, vector<vector< int>> &edges)
    {
        int N = vals.size(), goodPaths = 0;
        vector<vector<int>> adj(N);
        map<int, vector<int>> sameValues;

        for (int i = 0; i < N; i++)
        {
            sameValues[vals[i]].push_back(i);
        }

        for (auto &e: edges)
        {
            int u = e[0], v = e[1];

            if (vals[u] >= vals[v])
            {
                adj[u].push_back(v);
            }
            else if (vals[u] < vals[v])
            {
                adj[v].push_back(u);
            }
        }

        DSU dsu(N);

        for (auto &[value, allNodes]: sameValues)
        {

            for (int u: allNodes)
            {
                for (int v: adj[u])
                {
                    dsu.connect(u, v);
                }
            }

            unordered_map<int, int> group;

            for (int u: allNodes)
            {
                group[dsu.findPar(u)]++;
            }

            goodPaths += allNodes.size();

            for (auto &[_, size]: group)
            {
                goodPaths += (size * (size - 1) / 2);
            }
        }
        return goodPaths;
    }
};