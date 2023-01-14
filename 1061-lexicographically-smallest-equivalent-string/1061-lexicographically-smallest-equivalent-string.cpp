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
            parent[i] = -1;
            rank[i] = 0;
            size[i] = 1;
        }
    }

    int findPar(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = findPar(parent[i]);
    }

    bool unionByRank(int a, int b)
    {
        int x = findPar(a), y = findPar(b);
//         if (x == y) return false;

//         if (rank[x] > rank[y]) parent[y] = x;
//         else if (rank[x] < rank[y]) parent[x] = y;
//         else
//         {
//             parent[x] = y;
//             rank[x]++;
//         }
        if(x != y) 
            parent[max(x,y)] = min(x, y);
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
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        DSU dsu(26);
        // union equalilant chars
        for (int i = 0; i < s1.size(); ++i) 
        {
             dsu.unionByRank(s1[i] - 'a', s2[i] - 'a');
        }
        for(auto i = 0; i < baseStr.size(); i++)
        {
            // find common parents
            baseStr[i] = dsu.findPar(baseStr[i] - 'a') + 'a';
        } 
        return baseStr;
    }
};