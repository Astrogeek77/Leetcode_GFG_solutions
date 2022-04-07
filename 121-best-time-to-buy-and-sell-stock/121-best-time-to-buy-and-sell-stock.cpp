class Solution {
public:
    int maxProfit(vector<int>& a) {
       
        int min_cp=INT_MAX;
        int profit=INT_MIN;
           
        for(int i=0;i<a.size();i++)
        {
		//logic
            if(a[i]<min_cp)
                min_cp=a[i];
            
            if(a[i]-min_cp>profit)
                profit=a[i]-min_cp;
        }
        
        return profit;
        
    }
};