class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& fb, int n) 
    {   
        if(n == 0) return true;
        for(int i = 0; i < fb.size(); i++)
        {
            if(fb[i] == 0 
               and (i == 0 or fb[i-1] == 0) 
               and (i == fb.size() - 1 or fb[i+1] == 0))
            {
                fb[i] = 1;
                if(--n == 0) return true;
            }
        }
        return false;
    }
};