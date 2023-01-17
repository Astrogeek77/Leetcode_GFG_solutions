class Solution {
public:
    int minFlipsMonoIncr(string s, int onesCount = 0, int flipCount = 0) 
    {
        for(char ch: s)
        {
            if(ch == '1') onesCount++;
            else flipCount++;
            
            flipCount = onesCount < flipCount ? onesCount : flipCount;
        }
        return flipCount;
    }
};