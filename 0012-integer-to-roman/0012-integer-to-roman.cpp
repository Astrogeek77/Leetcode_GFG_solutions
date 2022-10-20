class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> map = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        string res;
        int lo = 0;
        
        while(num > 0)
        {
            while(map[lo].first > num) lo++;
            
            res += map[lo].second;
            num -= map[lo].first;
        }
        return res;
    }
};