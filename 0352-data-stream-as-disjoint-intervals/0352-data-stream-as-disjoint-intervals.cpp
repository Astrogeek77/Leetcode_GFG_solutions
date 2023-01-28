class SummaryRanges 
{
    // we use a set for unique values and order
    set<int> st;
public:
    SummaryRanges() 
    {
        // clear set at the mount
        st.clear();
    }
    
    void addNum(int value) 
    {
        // insert value to the set
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() 
    {
        vector<vector<int>> ans;
        
        // to get the disjoint intervals we traverse the set
        if(!st.empty())
        {
            int left = (*st.begin()), right = (*st.begin());
            set<int> :: iterator it;
            
            for(it = ++(st.begin()); it != st.end(); it++)
            {
                int val = (*it);
                if(val == right + 1)
                {
                   right = val; 
                }
                else 
                {
                    ans.push_back({left, right});
                    left = val;
                    right = val;
                }
            }
            ans.push_back({left, right});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */