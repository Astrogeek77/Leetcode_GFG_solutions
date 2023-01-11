class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> ans;
        // Cases:
        // the new interval is after the range of other interval
        // the new interval's range is before the other interval
        // the new interval is in the range of the other interval
        
        for(vector<int> interval: intervals)
        {
            // case 1
            // interval->endtime < newInterval->starttime
            if(interval[1] < newInterval[0]) 
                ans.push_back(interval);
            
            // case 2
            // interval->starttime > newInterval->endtime
            else if(interval[0] > newInterval[1])
                ans.push_back(newInterval), newInterval = interval;
            
            // case 3
            else if(interval[1] >= newInterval[0] or interval[0] <= newInterval[0])
                newInterval[0] = min(interval[0], newInterval[0]),
                newInterval[1] = max(interval[1], newInterval[1]);
            
        }
        ans.push_back(newInterval);
        return ans;
    }
};