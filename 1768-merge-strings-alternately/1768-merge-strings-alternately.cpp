class Solution {
public:
    string mergeAlternately(string w1, string w2) 
    {
        string res = "";
        int size = max(w1.size(), w2.size());

        for (auto i = 0; i < size; i++) 
        {
            if (i < w1.size()) res += w1[i];
            if (i < w2.size()) res += w2[i];
        }
        return res;
    }
};