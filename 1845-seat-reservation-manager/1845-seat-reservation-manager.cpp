class SeatManager
{
    public:
    set<int> s;
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++) s.insert(i);
    }

    int reserve()
    {
        // as the set is ordered, returns the minumum number from set i.e begining of set
        auto i = s.begin();
        int n = *i;
        s.erase(i);
        return n;
    }

    void unreserve(int n)
    {
        s.insert(n);
    }
};

/**
 *Your SeatManager object will be instantiated and called as such:
 *SeatManager* obj = new SeatManager(n);
 *int param_1 = obj->reserve();
 *obj->unreserve(seatNumber);
 */