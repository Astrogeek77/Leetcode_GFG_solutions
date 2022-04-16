class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I']=1;
        m['IV']=4;
        m['V']=5;
        m['IX']=9;
        m['X']=10;
        m['XL']=40;
        m['L']=50;
        m['XC']=90;
        m['C']=100;
        m['CD']=400;
        m['D']=500;
        m['CM']=900;
        m['M']=1000;
        
        int ans = m[s[0]];
        char pre = s[0];
        
        for(int i = 1; i < s.length(); i++){
            ans += m[s[i]];
            
            if(m[pre] < m[s[i]]) ans = ans - 2 * m[pre];
            pre = s[i];
        }
        return ans;
    }
};