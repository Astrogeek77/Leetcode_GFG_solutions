class Solution {
public:
    int bestClosingTime(string cust) {
        int yCnt = 0, nCnt = 0;
        
        // count Y's
        for(int i = 0; i < cust.size(); i++)
        {
            if(cust[i] == 'Y') yCnt++;
        }
        
        int penalty = 0, minTime = 1e9, minPenalty = 1e9;
        
        for(int i = 0; i <= cust.size(); i++)
        {
            // penalty will be equal to
            penalty = yCnt + nCnt;
            
            // if out current penalty is less, update the minpenalty
            if(minPenalty > penalty)
            {
                minTime = i;
                minPenalty = penalty;
            }
            
            // update counters while traversing
            if(i < cust.size() and cust[i] == 'N') nCnt++;
            if(i < cust.size() and cust[i] == 'Y') yCnt--;
        }
        return minTime;
    }
};