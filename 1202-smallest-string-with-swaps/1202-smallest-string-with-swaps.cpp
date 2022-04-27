class Solution {
    unordered_map<int, int> m;
public:
    void init_map(string s){
        for(int i = 0 ; i < s.size(); ++i){
            m[i] = i;
        }
    }
    
    int find(int a){
        if(m[a] == a) return a;
        return m[a] = find(m[a]);
    }
    
    void union_set(int a, int b){
        int x = find(m[a]);
        int y = find(m[b]);
        if ( x == y) return;
        m[x] = y;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        init_map(s);
            
        for(int i = 0 ; i < pairs.size(); ++i){
            union_set(pairs[i][0], pairs[i][1]);
        }
        
        vector<vector<char>> chars(s.size()); 
        vector<vector<int>> indexes(s.size());
		
        for(int i = 0; i < s.size(); ++i){
            int r = find(m[i]);
            chars[r].push_back(s[i]);
            indexes[r].push_back(i);
        }
        
        for(int k = 0; k < s.size(); ++k){
            if(chars[k].size()){
                sort(chars[k].begin(),chars[k].end());
            }
            
            for(int len = 0; len < chars[k].size(); ++len){
                s[indexes[k][len]] = chars[k][len];
            }
        }        
        return s;
    }
};