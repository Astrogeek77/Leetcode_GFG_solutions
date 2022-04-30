class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> g; // directed graph
        int n = values.size();
        for(int i = 0; i<n; i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            
            g[u].push_back({v, val});
            g[v].push_back({u, 1/val});
        }
        
        
        vector<double> ans;
        ans.reserve(queries.size());
        
        for(auto &q: queries)
        {
            string u = q[0];
            string v = q[1];
            if(g.count(u)==0 or g.count(v)==0)
            {
                ans.push_back(-1);
                continue;
            }
            
            if(v==u)
            {
                ans.push_back(1);
                continue;
            }
            
            unordered_map<string, bool> visited;
            double a = dfs(g, u, visited, v);
            ans.push_back(a);
        }
        
        return ans;
        
    }
    
    double dfs (unordered_map<string, 
                vector<pair<string, double>>> &g,
                string &node, unordered_map<string, bool> &visited, 
                string &target)
    {
        visited[node] = true;
        
        for(auto &nbr: g[node])
        {
            string v = nbr.first;
            double val = nbr.second;
            
            if(v==target)
            {
                return val;
            }
            
            double curr = -1;
            if(visited[v]==false)
            {
                double ret = dfs(g, v, visited, target);
                if(ret!=-1)
                {
                    return ret*val;
                }
                
            }
        }
        
        return -1;
    }
};