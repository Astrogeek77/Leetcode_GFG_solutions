class RandomizedCollection 
{
    public:
    vector<int> arr;
    unordered_map<int, int> set;
    RandomizedCollection()
    {
       	// set and arr are already intialized to 0
    }

    bool insert(int val)
    {
        if(set[val] == 0) 
        {
            arr.push_back(val);
            set[val]++;
            return true;
        } 
        else if (set[val] > 0) 
        {
            arr.push_back(val);
            set[val]++;
            return false;
        }
        return false;
    }

    bool remove(int val)
    {
        if(set[val] > 0)
        {
            auto it = find(arr.begin(), arr.end(), val);
            arr.erase(it);
            set[val]--;
            return true;
        }
        return false;
    }

    int getRandom()
    {
        if(arr.size() == 0) return arr[0];
        int random = rand() % arr.size();
        return arr[random];
    }
};

/**
 *Your RandomizedSet object will be instantiated and called as such:
 *RandomizedSet* obj = new RandomizedSet();
 *bool param_1 = obj->insert(val);
 *bool param_2 = obj->remove(val);
 *int param_3 = obj->getRandom();
 */

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */