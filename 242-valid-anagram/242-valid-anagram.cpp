class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        
        map<char, int> tmap;
        map<char, int> smap;
        
        for(auto ch : s) smap[ch]++;
        for(auto ch : t) tmap[ch]++;
        
        for(auto x : smap){
            char ch = x.first;
            int num = x.second;
            
            if(tmap[ch] != num) return false;
        }
     return true;       

    }
};